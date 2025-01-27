#include <stdio.h>
#include <assert.h>
#include "Set.h"
#include "Graph.h"

// ANSI colour codes
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"

Set reachable(Graph g, Vertex src);
static void dfs(Graph g, Vertex v, Set visited);

// -----------------------------------------------------------------------------
// Helper function to print test results in colour
// -----------------------------------------------------------------------------
static void run_test(const char *test_name, bool condition) {
    if (condition) {
        printf("%sTest %s: PASSED%s\n", GREEN, test_name, RESET);
    } else {
        printf("%sTest %s: FAILED%s\n", RED, test_name, RESET);
    }
}

// -----------------------------------------------------------------------------
// Helper function to print test suite headers
// -----------------------------------------------------------------------------
static void print_test_suite_header(const char *suite_name) {
    printf("\nTest Suite: %s\n", suite_name);
    printf("-----------------------\n");
}

// -----------------------------------------------------------------------------
// Helper function to check if a Set contains exactly a given array of vertices
// -----------------------------------------------------------------------------
static bool checkSetContents(Set s, Vertex *expected, int nExpected) {
    // Check size first
    if (SetSize(s) != nExpected) {
        return false;
    }

    // Then check each expected element
    for (int i = 0; i < nExpected; i++) {
        if (!SetContains(s, expected[i])) {
            return false;
        }
    }
    return true;
}

// -----------------------------------------------------------------------------
// Test 1: Reachable in an Empty Graph
// -----------------------------------------------------------------------------
static void test_emptyGraph(void) {
    print_test_suite_header("test_emptyGraph");

    // Create an empty graph with 0 vertices.
    Graph g = GraphNew(0);

    // If your code defines behavior for an empty graph,
    // you might expect an empty set back from reachable.
    // We'll assume the function just returns an empty set and doesn't crash.
    Set result = reachable(g, 0); // vertex 0 won't even exist, but let's see

    // Expect an empty set
    bool test1 = (SetSize(result) == 0);
    run_test("Reachable on empty graph => empty set", test1);

    SetFree(result);
    GraphFree(g);
}

// -----------------------------------------------------------------------------
// Test 2: Reachable in a Single Vertex Graph
// -----------------------------------------------------------------------------
static void test_singleVertex(void) {
    print_test_suite_header("test_singleVertex");

    // Create a graph with 1 vertex (vertex 0).
    Graph g = GraphNew(1);

    // No edges to insert; there's only one vertex.

    // Now call reachable from vertex 0
    Set result = reachable(g, 0);

    // We expect the reachable set to contain just {0}.
    Vertex expected[] = {0};
    bool test1 = checkSetContents(result, expected, 1);
    run_test("Reachable in single-vertex graph => {0}", test1);

    SetFree(result);
    GraphFree(g);
}

// -----------------------------------------------------------------------------
// Test 3: Reachable in a Small Connected Graph
// (e.g., 4 vertices, all connected in a chain or fully connected)
// -----------------------------------------------------------------------------
static void test_smallConnectedGraph(void) {
    print_test_suite_header("test_smallConnectedGraph");

    // Create a graph with 4 vertices: 0, 1, 2, 3
    Graph g = GraphNew(4);

    // Let's connect them in a chain: 0->1, 1->2, 2->3
    // For simplicity, let's make it undirected-like by adding reciprocal edges
    GraphInsertEdge(g, 0, 1);
    GraphInsertEdge(g, 1, 0);
    GraphInsertEdge(g, 1, 2);
    GraphInsertEdge(g, 2, 1);
    GraphInsertEdge(g, 2, 3);
    GraphInsertEdge(g, 3, 2);

    // Now check reachable from vertex 0
    Set result0 = reachable(g, 0);
    Vertex expected0[] = {0, 1, 2, 3};
    bool test0 = checkSetContents(result0, expected0, 4);
    run_test("Reachable from 0 => {0, 1, 2, 3}", test0);

    // Also check reachable from vertex 2
    SetFree(result0);
    Set result2 = reachable(g, 2);
    Vertex expected2[] = {0, 1, 2, 3}; 
    bool test1 = checkSetContents(result2, expected2, 4);
    run_test("Reachable from 2 => {0, 1, 2, 3}", test1);

    SetFree(result2);
    GraphFree(g);
}

// -----------------------------------------------------------------------------
// Test 4: Reachable in a Disconnected Graph
// (e.g., 5 vertices, but split into two disconnected subgraphs)
// -----------------------------------------------------------------------------
static void test_disconnectedGraph(void) {
    print_test_suite_header("test_disconnectedGraph");

    // Create a graph with 5 vertices: 0, 1, 2, 3, 4
    Graph g = GraphNew(5);

    // Subgraph 1: connect 0->1, 1->0, 1->2, 2->1
    GraphInsertEdge(g, 0, 1);
    GraphInsertEdge(g, 1, 0);
    GraphInsertEdge(g, 1, 2);
    GraphInsertEdge(g, 2, 1);

    // Subgraph 2: connect 3->4, 4->3
    GraphInsertEdge(g, 3, 4);
    GraphInsertEdge(g, 4, 3);

    // Check reachable from vertex 0 => should be {0, 1, 2}
    Set r0 = reachable(g, 0);
    Vertex expected0[] = {0, 1, 2};
    bool test0 = checkSetContents(r0, expected0, 3);
    run_test("Reachable from 0 => {0, 1, 2}", test0);

    // Check reachable from vertex 3 => should be {3, 4}
    SetFree(r0);
    Set r3 = reachable(g, 3);
    Vertex expected3[] = {3, 4};
    bool test1 = checkSetContents(r3, expected3, 2);
    run_test("Reachable from 3 => {3, 4}", test1);

    // Check reachable from vertex 4 => should be {3, 4} 
    // to confirm we don't pick up the other subgraph
    SetFree(r3);
    Set r4 = reachable(g, 4);
    Vertex expected4[] = {3, 4};
    bool test2 = checkSetContents(r4, expected4, 2);
    run_test("Reachable from 4 => {3, 4}", test2);

    // Vertex 2 => {0, 1, 2}
    SetFree(r4);
    Set r2 = reachable(g, 2);
    Vertex expected2[] = {0, 1, 2};
    bool test3 = checkSetContents(r2, expected2, 3);
    run_test("Reachable from 2 => {0, 1, 2}", test3);

    SetFree(r2);
    GraphFree(g);
}

// -----------------------------------------------------------------------------
// Combine all tests
// -----------------------------------------------------------------------------
static void run_tests(void) {
    test_emptyGraph();
    test_singleVertex();
    test_smallConnectedGraph();
    test_disconnectedGraph();
}

int main(void) {
    run_tests();
    return 0;
}

Set reachable(Graph g, Vertex src) {
    Set visited = SetNew();
    if (GraphNumVertices(g) == 0) return visited;
    dfs(g, src, visited);
    return visited;
}

static void dfs(Graph g, Vertex v, Set visited) {
    SetInsert(visited, v);
    for (int w = 0; w < GraphNumVertices(g); w++) {
        if (GraphIsAdjacent(g, v, w) && !SetContains(visited, w)) {
            dfs(g, w, visited);
        }
    }
}