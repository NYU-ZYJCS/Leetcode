<h2><a href="https://leetcode.com/problems/ones-and-zeroes/solution/"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">474. </font><font style="vertical-align: inherit;">1 和</font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">0</font></font><font style="vertical-align: inherit;"></font></a></h2><h3>Medium</h3><hr><div><p><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">给定一个二进制字符串数组</font></font><code>strs</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">和两个整数</font></font><code>m</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">和</font></font><code>n</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">。</font></font></p>

<p><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">返回</font></font><em><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">的最大子集的大小，</font></font><code>strs</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">使得</font></font><strong><font style="vertical-align: inherit;"></font></strong> </em><font style="vertical-align: inherit;"><em><font style="vertical-align: inherit;">子集中</font></em><em><strong><font style="vertical-align: inherit;">最多</font></strong></em><em><font style="vertical-align: inherit;">有和</font></em><font style="vertical-align: inherit;">。</font></font><code>m</code><em> </em><code>0</code><em><font style="vertical-align: inherit;"></font></em><code>n</code><em> </em><code>1</code><em><font style="vertical-align: inherit;"></font></em><font style="vertical-align: inherit;"></font></p>

<p><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">如果 的所有元素</font><font style="vertical-align: inherit;">也是 的元素，则</font><font style="vertical-align: inherit;">集合</font></font><code>x</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">是</font><font style="vertical-align: inherit;">的</font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">子集</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">。</font></font><code>y</code><font style="vertical-align: inherit;"></font><code>x</code><font style="vertical-align: inherit;"></font><code>y</code><font style="vertical-align: inherit;"></font></p>

<p>&nbsp;</p>
<p><strong class="example"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">示例 1：</font></font></strong></p>

<pre><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">输入：</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> strs = ["10","0001","111001","1","0"], m = 5, n = 3
</font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">输出：</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> 4
</font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">解释：</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">最多包含 5 个 0 和 3 个 1 的最大子集是 {"10", "0001", "1", "0"}，因此答案为 4。</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
其他有效但较小的子集包括 {“0001”、“1”} 和 {“10”、“1”、“0”}。</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
{“111001”} 是无效子集，因为它包含 4 个 1，大于最大值 3。</font></font><font></font>
</pre>

<p><strong class="example"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">示例 2：</font></font></strong></p>

<pre><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">输入：</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> strs = ["10","0","1"], m = 1, n = 1
</font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">输出：</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> 2
</font></font><b><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">解释：</font></font></b><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">最大的子集是 {"0", "1"}，所以答案是 2。
</font></font></pre>

<p>&nbsp;</p>
<p><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">限制：</font></font></strong></p>

<ul>
	<li><code>1 &lt;= strs.length &lt;= 600</code></li>
	<li><code>1 &lt;= strs[i].length &lt;= 100</code></li>
	<li><code>strs[i]</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">仅由数字</font></font><code>'0'</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">和组成</font></font><code>'1'</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">。</font></font></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
</ul>
</div>