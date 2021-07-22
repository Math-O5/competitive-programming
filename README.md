# CP - COMPETITIVE_PROGRAMMING

  Here are some resolutions of competitive programming. I like to do this problems to improve my skills coding, distract from the dayly tasks. Note, this code is really messy up, since is done only to be 'accepted".  

# Algorithms and Applications
<p>The link of the problems is commented first line of each code. The sections are splitted by Event (Advent of Code, Daily Byte and etc) and by theme (Greedy, DP and etc). If there are more than one solution, then it will be chained as follow: [1][2]. Sometime, the complexity time is given in the link, instead of enumerating [O(n)][O(nlogn)]./p>
<ul>
    <li>
      <h2>Advent of the Code 2020 | 2021 <a href="https://github.com/Math-O5/competitive-programming/tree/master/ADVENT_OF_THE_CODE">solutions</a></h2><p>Cool challenges in increase difficulty order, summer challenges.</p>
    </li>
    <li>
      <h2>Daily Byte <a href="https://github.com/Math-O5/competitive-programming/tree/master/DailyCode">solutions</a></h2><p>Every day a learning day.</p>
    </li>
    <li>
      <h2>DP - <a href="https://en.wikipedia.org/wiki/Dynamic_programming" target="_blank">Programming Dinamic</a></h2>
      <ul>
        <li><a href="ALGORITHMS/dp/range-sum.cpp" target="_blank">[1]</a> Range Sum</li>
        <li><a href="ALGORITHMS/dp/lis-dp.cpp" target="_blank">[1] </a> <a href="ALGORITHMS/dp/lis-bs.cpp">[2]</a> Longest Increase Sequence</li>
        <li><a href="ALGORITHMS/dp/wisp-dp.cpp" target="_blank">[1]</a> Weithed Interval Schedule Problem</li>
        <li><a href="ALGORITHMS/dp/wssp-dp.cpp" target="_blank">[1]</a> Knapsack</li>
        <li><a href="ALGORITHMS/dp/coin-dp.cpp" target="_blank">[1]</a> Coin Change</li>
      </ul>
      <h2>Pratice DP</h2>
      <ul>
          <li><a href="OTHERS/meu-troco.cpp">[1] </a><a href="OTHERS/meu-troco2.cpp">[2]</a><a href="OTHERS/meu-troco3.cpp"> [3]</a> Véi, dá meu troco! - (DP - Coins)</li>
          <li><a href="OBI/2015/banco-inteligente.cpp">[1]</a><a href="UVA/357-let-count-the-ways.cpp">[2]</a> Formas de me dar meu dinheiro! (ways to count) (DP - Coin)</li>
          <li><a href="UVA/p507.cpp">[1]</a> UVA 507 Jill Rides Again - (DP - Sum Range)</li>
          <li><a href="OBI/2014/letra.cpp ">[1]</a> OBI 2014 Letra - (DP - LIS)</li>
          <li><a href="UVA/p10543.cpp">[1]</a> UVA 10534 - Wavio Sequence (DP - LIS)</li>
          <li><a href="OBI/2007/pizza.cpp">[1]</a> OBI 2007 Pizza - (DP - Sum Range)</li>
          <li><a href="UVA/10131-is-bigger-smarter.cpp">[1] O(n²) - </a><a href="UVA/10131-is-bigger-smarter2.cpp">[2] O(n log n)</a> UVA 10131 is bigger smarter?- (DP - LIS)</li>
          <li><a href="OTHERS/DNA-Sequence-Alignment.cpp">[1] O(n*m)</a> DNA Sequence Alignment (DP - String)</li>
          <li><a href="OBI/2005/pedido_de_desculpas.cpp">[1] O(n²)</a> OBI 2005 Pedido de desculpas - (DP - Knapsack)</li>
          <li><a href="UVA/10616-divisible.cpp">[1] O(n²)</a> UVA 10616 Sum Divisble by n chosen m - (DP - Knapsack)</li>
      </ul>
    </li>
    <li>
     <h2>Strings - <a href="https://en.wikibooks.org/wiki/A-level_Computing/AQA/Paper_1/Fundamentals_of_data_structures/Graphs" target="_blank">Strings in CP</a></h2>
      <ul>
        <li><a href="ALGORITHMS/strings/counting_sort.cpp" target="_blank">[1]</a> Counting Sort</li>
        <li><a href="ALGORITHMS/strings/radix_sort.cpp" target="_blank">[1]</a> Radix Sort</li>
        <li><a href="ALGORITHMS/strings/prefix_function.cpp" target="_blank">[O(n)]</a> Prefix Function</li>
        <li><a href="ALGORITHMS/strings/matching_01.cpp" target="_blank">[O(mn)]</a> KMP Naive</li>
      </ul>
      <h2>Pratice Strings</h2>
      <ul>
          <li><a href="OBI/2010/fusões.cpp">[1]</a><a href="OTHERS/guildas.cpp">[2]</a> OBI Fusões - Guildas (Graph - Union Find)</li>
      </ul>
    </li>
    <li>
     <h2>Graph - <a href="https://en.wikibooks.org/wiki/A-level_Computing/AQA/Paper_1/Fundamentals_of_data_structures/Graphs" target="_blank">Graph in CP (Grafos)</a></h2>
      <ul>
        <li><a href="ALGORITHMS/graph/union-find.cpp" target="_blank">[1]</a> Union Find (DSU)</li>
        <li><a href="ALGORITHMS/graph/dfs.cpp" target="_blank">[1]</a> DFS (Deep First Search)</li>
        <li><a href="ALGORITHMS/graph/bfs.cpp" target="_blank">[1]</a> BFS (Breadth First Search)</li>
        <li><a href="ALGORITHMS/graph/dijkstra.cpp" target="_blank">[1]</a> Dijkstra</li>
        <li><a href="ALGORITHMS/graph/prim.cpp" target="_blank">[1]</a> Prim's Algorithm</li>
        <li><a href="ALGORITHMS/graph/kruskal.cpp" target="_blank">[1] O(M log N) - </a><a href="ALGORITHMS/graph/mst_fast_one.cpp" target="_blank">[2]</a> MST (Minimum spanning  - Kruskal)</li>
        <li><a href="ALGORITHMS/graph/ordenacao-topologica.cpp" target="_blank">[BFS] </a><a href="ALGORITHMS/graph/ordenacao-topologica-2.cpp" target="_blank">[DFS]</a> versão da Ordenação Topologica (Top Sorting)</li>
        <li><a href="ALGORITHMS/graph/bellman-ford.cpp" target="_blank">[1] O(|V| * |E|) -</a> Bellforman Ford (Min Path)</li>
        <li><a href="ALGORITHMS/graph/bipartite.cpp" target="_blank">[1] O(|V| * |E|) -</a> Check Graph Bipartite (BFS/DFS)</li>
        <li><a href="ALGORITHMS/graph/floyd-warshal.cpp" target="_blank">[1] O(N³) -</a> Floyd-Warshall (Min Path to all vertices)</li>
      </ul>
      <h2>Pratice Graphs</h2>
      <ul>
          <li><a href="OBI/2010/fusões.cpp">[1]</a><a href="OTHERS/guildas.cpp">[2]</a> OBI Fusões - Guildas (Graph - Union Find)</li>
          <li><a href="CODEFORCES/c-new-distribution.cpp">[1]</a> CODEFORCES 69 - C - new Distribution (Graph - DFS or Union Find)</li>
          <li><a href="OBI/2016/taco_do_saci.cpp">[1]</a> OBI 2016 - Taco do Saci (Graph - DFS)</li>
          <li><a href="OBI/2011/escalonamento.cpp">[1] O(|V| + |E|)</a> OBI 2011 - Escalonamento Ótimo (Graph - Ordenação Topológica)</li>
          <li><a href="OBI/2014/copa-do-mundo.cpp">[1] O(|M| log |N|)</a> OBI - Copa do Mundo 2014 (Kruskal - MST)</li>
          <li><a href="UVA/558-Wormholes.cpp">[1] O(|V| * |E|)</a> UVA 558 - Wormholes (Graph - Negative Cycles)</li>
          <li><a href="CODEFORCES/div3/617-E-graph.cpp">[1] </a> CODEFORCES 617 - E - String Coloring, Easy Version (Graph - Bipartite)</li>  
          <li><a href="OBI/2010/reuniao.cpp">[OBI- 2010 - Reuniao] </a> Floyd Warshall </li>  
      </ul>
    </li>
    <li>
      <h2>Greedy / Brute Force Problems</h2>
      <ul>
        <li><a href="OBI/2010/dentista_1.cpp">[1] O(N logn N) - [2] O(N) </a> OBI 2010 Dentista (Intervel schedule)</li>
        <li><a href="CODEFORCES/div3/617-E-greedy.cpp">[1] </a> CODEFORCES 617 - E - String Coloring, Easy Version (Greedy Solution)</li>
        <li><a href="CODEFORCES/FREE_CAMP/gulosos/palindromic_path.cpp">[1] </a> CODEFORCES - Palindromos</li>
        <li><a href="CODEFORCES/ALGORITHMS/greedy/knights.cpp">[1] </a> </li>
      </ul>
    </li>
    <li>
      <h2>DATA STRUCTURE</h2>
      <ul>
        <li><a href="ALGORITHMS/struct/stl-1.md" target="_blank">[1]</a> STL 1 (vector, queue, stack, pair)</li>
        <li><a href="ALGORITHMS/struct/stl-2.md" target="_blank">[1]</a> STL 2 (map, set, tree)</li>
        <li><a href="ALGORITHMS/struct/bits-1.md" target="_blank">[1]</a><a href="ALGORITHMS/struct/bits-2.md" target="_blank"> [2]</a> Bits (Bits)</li>
        <li><a href="ALGORITHMS/struct/bs.md" target="_blank">[1]</a> Binary Search Tree</li>
        <li><a href="ALGORITHMS/struct/segTree.cpp" target="_blank">[1]</a> Segmented tree (seg Tree)</li>
      </ul>
      <h2>Pratice</h2>
      <ul>
        <li><a href="OBI/2016/times.cpp">[1]</a> OBI 2016 - Times (Vectors and Pairs)</li>
        <li><a href="OBI/2014/fila.cpp">[1]</a> OBI 2014 - Fila (Bits)</li>
        <li><a href="CODEFORCES/div3/570-C.cpp">[1]</a> CODEFORCES DIV3 570 - D Computer Game (Binary Search)</li>
        <li><a href="UVA/p540_team_queue.cpp" target="_blank">[1]</a> UVA 540 Team Queue (Map)</li>
        <li><a href="UVA/p837.cpp" target="_blank">[1]</a> UVA 837 Light and Transparencies (Map, Set)</li>
        <li><a href="OBI/2012/banco.cpp" target="_blank">[1]</a> OBI Banco (Priority Queue)</li>
        <li><a href="OBI/2012/soma-de-casas-2.cpp" target="_blank">[1] U(n log n)</a> OBI Banco (Binary Search)</li>
      </ul>
    </li>
</ul>
