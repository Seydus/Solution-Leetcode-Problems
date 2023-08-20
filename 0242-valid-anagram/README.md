<h2><a href="https://leetcode.com/problems/valid-anagram/">242. Valid Anagram</a></h2>
<h3>Easy</h3>
<hr>
<div>
<p>Given two strings <code>s</code> and <code>t</code>, return <em>true</em> if <code>t</code> is an anagram of <code>s</code>, and <em>false</em> otherwise.</p>
<p>An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.</p>
<h4>Example 1:</h4>
<pre><strong>Input:</strong> s = "anagram", t = "nagaram"
<strong>Output:</strong> true</pre>
<h4>Example 2:</h4>
<pre><strong>Input:</strong> s = "rat", t = "car"
<strong>Output:</strong> false</pre>
<p><strong>Constraints:</strong></p>
<ul>
<li><code>1 &lt;= s.length, t.length &lt;= 5 * 10^4</code></li>
<li><code>s</code> and <code>t</code> consist of lowercase English letters.</li>
</ul>
<p><strong>Follow up:</strong> What if the inputs contain Unicode characters? How would you adapt your solution to such a case?</p>
</div>
<h2><a href="https://leetcode.com/problems/number-of-good-pairs/">1512. Number of Good Pairs</a></h2>
<h3>Easy</h3>
<hr>
<div>
<p>Given an array of integers <code>nums</code>, return <em>the number of <strong>good pairs</strong></em>.</p>
<p>A pair <code>(i, j)</code> is called <em>good</em> if <code>nums[i] == nums[j]</code> and <code>i</code> &lt; <code>j</code>.</p>
<h4>Example 1:</h4>
<pre><strong>Input:</strong> nums = [1,2,3,1,1,3]
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.</pre>
<h4>Example 2:</h4>
<pre><strong>Input:</strong> nums = [1,1,1,1]
<strong>Output:</strong> 6
<strong>Explanation:</strong> Each pair in the array is <em>good</em>.</pre>
<h4>Example 3:</h4>
<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> 0</pre>
<p><strong>Constraints:</strong></p>
<ul>
<li><code>1 &lt;= nums.length &lt;= 100</code></li>
<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>
</div>
