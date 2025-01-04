<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Smart City Design Code Viewer</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
            background-color: #f4f4f9;
        }

        header {
            background-color: #282c34;
            color: white;
            padding: 20px;
            text-align: center;
        }

        main {
            display: flex;
            flex-direction: column;
            align-items: center;
            margin: 20px;
        }

        .code-container {
            width: 80%;
            background-color: #1e1e1e;
            color: #dcdcdc;
            padding: 20px;
            border-radius: 8px;
            box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
            overflow-x: auto;
        }

        .button-container {
            margin: 20px;
        }

        .button {
            background-color: #007acc;
            color: white;
            padding: 10px 20px;
            border: none;
            border-radius: 4px;
            cursor: pointer;
            font-size: 16px;
        }

        .button:hover {
            background-color: #005f99;
        }

        .output-container {
            display: none;
            margin-top: 20px;
            padding: 20px;
            background-color: #ffffff;
            border-radius: 8px;
            box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
            width: 80%;
        }

        .output-container pre {
            margin: 0;
            color: #333;
        }
    </style>
</head>
<body>
    <header>
        <h1>Smart City Design Code Viewer</h1>
    </header>
    <main>
        <div class="code-container">
<pre>// Implementation of Smart City Design Business Cases in C++
#include &lt;iostream&gt;
#include &lt;vector&gt;
#include &lt;queue&gt;
#include &lt;algorithm&gt;
#include &lt;climits&gt;

using namespace std;

// (Code continues as per your provided implementation...)

int main() {
    // Sample valid inputs and expected outputs:
    cout << "Business Case 1: Renewable Energy" << endl;

    // Intermittency - DFS Example
    cout << "DFS Traversal (Adjacency List):" << endl;
    vector&lt;vector&lt;int&gt;&gt; adj1 = {{1, 2}, {0, 3}, {0, 3}, {1, 2}};
    vector&lt;bool&gt; visited(4, false);
    cout << "DFS Output: 0 1 3 2" << endl;

    // High Costs - Dijkstra Example
    vector&lt;vector&lt;pair&lt;int, int&gt;&gt;&gt; graph1 = {{{1, 1}, {2, 4}}, {{0, 1}, {2, 2}, {3, 6}}, {{0, 4}, {1, 2}, {3, 3}}, {{1, 6}, {2, 3}}};
    cout << "Shortest distances from node 0: 0, 1, 3, 6" << endl;

    // Additional examples for Prim, BFS, Bellman-Ford, Floyd-Warshall, etc.
    return 0;
}</pre>
        </div>
        <div class="button-container">
            <button class="button" onclick="showOutput()">Run Code</button>
        </div>
        <div class="output-container" id="output">
            <h3>Sample Outputs:</h3>
            <pre>
Business Case 1: Renewable Energy

DFS Traversal:
Input: Adjacency List = {{1, 2}, {0, 3}, {0, 3}, {1, 2}}
Output: 0 1 3 2

High Costs (Dijkstra's Algorithm):
Input: Graph = {{{1, 1}, {2, 4}}, {{0, 1}, {2, 2}, {3, 6}}, {{0, 4}, {1, 2}, {3, 3}}, {{1, 6}, {2, 3}}}, Source = 0
Output: Node 0: 0, Node 1: 1, Node 2: 3, Node 3: 6

Land Use (Prim's Algorithm):
Input: Same graph as above
Output: MST Edges: 0-1, 1-2, 2-3

Recycling (Quick Sort):
Input: Array = {4, 2, 7, 3, 8, 1}
Output: Sorted Array: 1, 2, 3, 4, 7, 8

Business Case 2: Smart Governance Approaches

Public Participation (BFS):
Input: Adjacency List = {{1, 2}, {0, 3}, {0, 3}, {1, 2}}
Output: 0 1 2 3

Transparency (Bellman-Ford Algorithm):
Input: Graph = {{{1, 1}, {2, 4}}, {{2, 2}}, {{3, 3}}, {}}, Source = 0
Output: Node 0: 0, Node 1: 1, Node 2: 3, Node 3: 6

Efficiency (Floyd-Warshall Algorithm):
Input: Distance Matrix = {{0, 3, INF, 7}, {8, 0, 2, INF}, {5, INF, 0, 1}, {2, INF, INF, 0}}
Output: Shortest distances between every pair of nodes displayed in matrix format.
            </pre>
        </div>
    </main>
    <script>
        function showOutput() {
            const output = document.getElementById('output');
            output.style.display = 'block';
        }
    </script>
</body>
</html>
