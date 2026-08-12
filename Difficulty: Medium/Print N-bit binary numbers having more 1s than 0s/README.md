<h2><a href="https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1">Print N-bit binary numbers having more 1s than 0s</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 14pt;">Given a positive integer <strong data-start="98" data-end="103">n</strong>, generate all <strong data-start="118" data-end="142">n-bit </strong>binary numbers such that, for every prefix of each binary number, the count of <strong data-start="207" data-end="214">1's</strong> is greater than or equal to the count of <strong data-start="260" data-end="267">0's</strong>. </span></p>
<p><span style="font-size: 14pt;">Return the binary numbers in <strong data-start="298" data-end="341">decreasing order </strong>of their decimal value.</span></p>
<p><strong><span style="font-size: 18px;">Examples :</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 2</span><span style="font-size: 18px;">
<strong style="font-size: 18px;">Output:</strong><span style="font-size: 18px;"> ["11", "10"]
</span><strong style="font-size: 18px;">Explanation:</strong><span style="font-size: 18px;"> Valid numbers are those where each prefix has more 1s than 0s:<br>11: all its prefixes (1 and 11) have more 1s than 0s.
10: all its prefixes (1 and 10) have more 1s than 0s.<br>So, the output is "11, 10".</span></span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 3
<strong>Output:</strong> ["111", "110", "101"]
<strong>Explanation:</strong> Valid numbers are those where each prefix has more 1s than 0s.<br>111: all its prefixes (1, 11, and 111) have more 1s than 0s.
110: all its prefixes (1, 11, and 110) have more 1s than 0s.<br>101: all its prefixes (1, 10, and 101) have more 1s than 0s.<br>So, the output is "111, 110, 101".</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1&nbsp;</span><span style="font-size: 18.6667px;">≤</span><span style="font-size: 18px;"> n&nbsp;</span><span style="font-size: 18.6667px;">≤</span><span style="font-size: 18px;">&nbsp;15</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Recursion</code>&nbsp;