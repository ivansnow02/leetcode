<p>请你来实现一个&nbsp;<code>myAtoi(string s)</code>&nbsp;函数，使其能将字符串转换成一个 32 位有符号整数。</p>

<p>函数&nbsp;<code>myAtoi(string s)</code> 的算法如下：</p>

<ol> 
 <li><strong>空格：</strong>读入字符串并丢弃无用的前导空格（<code>" "</code>）</li> 
 <li><strong>符号：</strong>检查下一个字符（假设还未到字符末尾）为&nbsp;<code>'-'</code> 还是 <code>'+'</code>。如果两者都不存在，则假定结果为正。</li> 
 <li><strong>转换：</strong>通过跳过前置零来读取该整数，直到遇到非数字字符或到达字符串的结尾。如果没有读取数字，则结果为0。</li> 
 <li><b>舍入：</b>如果整数数超过 32 位有符号整数范围 <code>[−2<sup>31</sup>,&nbsp; 2<sup>31&nbsp;</sup>− 1]</code> ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 <code>−2<sup>31</sup></code> 的整数应该被舍入为 <code>−2<sup>31</sup></code> ，大于 <code>2<sup>31&nbsp;</sup>− 1</code> 的整数应该被舍入为 <code>2<sup>31&nbsp;</sup>− 1</code> 。</li> 
</ol>

<p>返回整数作为最终结果。</p>

<p>&nbsp;</p>

<p><strong class="example">示例&nbsp;1：</strong></p>

<div class="example-block"> 
 <p><strong>输入：</strong><span class="example-io">s = "42"</span></p> 
</div>

<p><strong>输出：</strong><span class="example-io">42</span></p>

<p><strong>解释：</strong>加粗的字符串为已经读入的字符，插入符号是当前读取的字符。</p>

<pre>
带下划线线的字符是所读的内容，插入符号是当前读入位置。
第 1 步："42"（当前没有读入字符，因为没有前导空格）
         ^
第 2 步："42"（当前没有读入字符，因为这里不存在 '-' 或者 '+'）
         ^
第 3 步："<u>42</u>"（读入 "42"）
           ^
</pre>


<p><strong class="example">示例&nbsp;2：</strong></p>

<div class="example-block"> 
 <p><strong>输入：</strong><span class="example-io">s = " -042"</span></p> 
</div>

<p><strong>输出：</strong><span class="example-io">-42</span></p>

<p><strong>解释：</strong></p>

<pre>
第 1 步："<u><strong>   </strong></u>-042"（读入前导空格，但忽视掉）
            ^
第 2 步："   <u>-</u>042"（读入 '-' 字符，所以结果应该是负数）
             ^
第 3 步："   <u>-042</u>"（读入 "042"，在结果中忽略前导零）
               ^
</pre>


<p><strong class="example">示例&nbsp;3：</strong></p>

<div class="example-block"> 
 <p><strong>输入：</strong><span class="example-io">s = "</span>1337c0d3<span class="example-io">"</span></p> 
</div>

<p><strong>输出：</strong><span class="example-io">1337</span></p>

<p><strong>解释：</strong></p>

<pre>
第 1 步："1337c0d3"（当前没有读入字符，因为没有前导空格）
         ^
第 2 步："1337c0d3"（当前没有读入字符，因为这里不存在 '-' 或者 '+'）
         ^
第 3 步："1337c0d3"（读入 "1337"；由于下一个字符不是一个数字，所以读入停止）
             ^
</pre>


<p><strong class="example">示例 4：</strong></p>

<div class="example-block"> 
 <p><strong>输入：</strong><span class="example-io">s = "0-1"</span></p> 
</div>

<p><span class="example-io"><b>输出：</b>0</span></p>

<p><strong>解释：</strong></p>

<pre>
第 1 步："0-1" (当前没有读入字符，因为没有前导空格)
         ^
第 2 步："0-1" (当前没有读入字符，因为这里不存在 '-' 或者 '+')
         ^
第 3 步："<u>0</u>-1" (读入 "0"；由于下一个字符不是一个数字，所以读入停止)
          ^
</pre>


<p><strong class="example">示例 5：</strong></p>

<div class="example-block"> 
 <p><strong>输入：</strong><span class="example-io">s = "words and 987"</span></p> 
</div>

<p><strong>输出：</strong><span class="example-io">0</span></p>

<p><strong>解释：</strong></p>

<p>读取在第一个非数字字符“w”处停止。</p>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul> 
 <li><code>0 &lt;= s.length &lt;= 200</code></li> 
 <li><code>s</code> 由英文字母（大写和小写）、数字（<code>0-9</code>）、<code>' '</code>、<code>'+'</code>、<code>'-'</code> 和 <code>'.'</code> 组成</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>字符串</details><br>

<div>👍 1899, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/issues' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.online/algo/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.online/algo/' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>

<div id="labuladong"><hr>

**通知：为满足广大读者的需求，网站上架 [速成目录](https://labuladong.online/algo/intro/quick-learning-plan/)
，如有需要可以看下，谢谢大家的支持~**

<details><summary><strong>labuladong 思路</strong></summary>


<div id="labuladong_solution_zh">

## 基本思路

这道题说实话没有什么难度，无非就是处理数字、符号、空格和 int 溢出的细节问题，具体看代码吧，把每一步的注释写清楚就不容易在细节上出错了。

**详细题解**：

- [【练习】数学技巧相关习题](https://labuladong.online/algo/problem-set/math-tricks/)

</div>





<div id="solution">

## 解法代码

<div class="tab-panel"><div class="tab-nav">
<button data-tab-item="cpp" class="tab-nav-button btn " data-tab-group="default" onclick="switchTab(this)">cpp🤖</button>

<button data-tab-item="python" class="tab-nav-button btn " data-tab-group="default" onclick="switchTab(this)">
python🤖</button>

<button data-tab-item="java" class="tab-nav-button btn active" data-tab-group="default" onclick="switchTab(this)">
java🟢</button>

<button data-tab-item="go" class="tab-nav-button btn " data-tab-group="default" onclick="switchTab(this)">go🤖</button>

<button data-tab-item="javascript" class="tab-nav-button btn " data-tab-group="default" onclick="switchTab(this)">
javascript🤖</button>
</div><div class="tab-content">
<div data-tab-item="cpp" class="tab-item " data-tab-group="default"><div class="highlight">

```cpp
// 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

class Solution {
public:
    int myAtoi(string str) {
        int n = str.length();
        int i = 0;
        // 记录正负号
        int sign = 1;
        // 用 long 避免 int 溢出
        long res = 0;
        // 跳过前导空格
        while (i < n && str[i] == ' ') {
            i++;
        }
        if (i == n) {
            return 0;
        }

        // 记录符号位
        if (str[i] == '-') {
            sign = -1;
            i++;
        } else if (str[i] == '+') {
            i++;
        }
        if (i == n) {
            return 0;
        }

        // 统计数字位
        while (i < n && '0' <= str[i] && str[i] <= '9') {
            res = res * 10 + str[i] - '0';
            if (res > INT_MAX) {
                break;
            }
            i++;
        }
        // 如果溢出，强转成 int 就会和真实值不同
        if ((int) res != res) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        return (int) res * sign;
    }
};
```

</div></div>

<div data-tab-item="python" class="tab-item " data-tab-group="default"><div class="highlight">

```python
# 注意：python 代码由 chatGPT🤖 根据我的 java 代码翻译。
# 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

class Solution:
    def myAtoi(self, str: str) -> int:
        n = len(str)
        i = 0
        # 记录正负号
        sign = 1
        # 用 long 避免 int 溢出
        res = 0
        # 跳过前导空格
        while i < n and str[i] == ' ':
            i += 1
        if i == n:
            return 0

        # 记录符号位
        if i < n and str[i] == '-':
            sign = -1
            i += 1
        elif i < n and str[i] == '+':
            i += 1
        if i == n:
            return 0

        # 统计数字位
        while i < n and '0' <= str[i] <= '9':
            res = res * 10 + ord(str[i]) - ord('0')
            # 溢出判断
            if sign == 1 and res > 2 ** 31 - 1:
                return 2 ** 31 - 1
            if sign == -1 and res > 2 ** 31:
                return -2 ** 31
            i += 1

        # 如果溢出，强转成 int 就会和真实值不同
        return int(res) * sign
```

</div></div>

<div data-tab-item="java" class="tab-item active" data-tab-group="default"><div class="highlight">

```java
class Solution {
    public int myAtoi(String str) {
        int n = str.length();
        int i = 0;
        // 记录正负号
        int sign = 1;
        // 用 long 避免 int 溢出
        long res = 0;
        // 跳过前导空格
        while (i < n && str.charAt(i) == ' ') {
            i++;
        }
        if (i == n) {
            return 0;
        }

        // 记录符号位
        if (str.charAt(i) == '-') {
            sign = -1;
            i++;
        } else if (str.charAt(i) == '+') {
            i++;
        }
        if (i == n) {
            return 0;
        }

        // 统计数字位
        while (i < n && '0' <= str.charAt(i) && str.charAt(i) <= '9') {
            res = res * 10 + str.charAt(i) - '0';
            if (res > Integer.MAX_VALUE) {
                break;
            }
            i++;
        }
        // 如果溢出，强转成 int 就会和真实值不同
        if ((int) res != res) {
            return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
        }
        return (int) res * sign;
    }
}
```

</div></div>

<div data-tab-item="go" class="tab-item " data-tab-group="default"><div class="highlight">

```go
// 注意：go 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

func myAtoi(str string) int {
n := len(str)
i := 0
// 记录正负号
sign := 1
// 用 int64 避免 int 溢出
res := int64(0)
// 跳过前导空格
for i < n && str[i] == ' ' {
i++
}
if i == n {
return 0
}

// 记录符号位
if str[i] == '-' {
sign = -1
i++
} else if str[i] == '+' {
i++
}
if i == n {
return 0
}

// 统计数字位
for i < n && '0' <= str[i] && str[i] <= '9' {
res = res * 10 + int64(str[i] - '0')
// Check for overflow after updating res
if res > int64(math.MaxInt32) {
// 如果溢出，强转成 int 就会和真实值不同
if sign == 1 {
return math.MaxInt32
} else {
return math.MinInt32
}
}
i++
}

// Apply the sign to the result and cast it to int before returning
return int(res * int64(sign))
}
```

</div></div>

<div data-tab-item="javascript" class="tab-item " data-tab-group="default"><div class="highlight">

```javascript
// 注意：javascript 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

var myAtoi = function (str) {
    let n = str.length;
    let i = 0;
    // 记录正负号
    let sign = 1;
    // 用 long 避免 int 溢出
    let res = 0;
    // 跳过前导空格
    while (i < n && str.charAt(i) === ' ') {
        i++;
    }
    if (i === n) {
        return 0;
    }

    // 记录符号位
    if (str.charAt(i) === '-') {
        sign = -1;
        i++;
    } else if (str.charAt(i) === '+') {
        i++;
    }
    if (i === n) {
        return 0;
    }

    // 统计数字位
    while (i < n && '0' <= str.charAt(i) && str.charAt(i) <= '9') {
        res = res * 10 + (str.charAt(i) - '0');
        if (res > 2147483647) { // Integer.MAX_VALUE
            break;
        }
        i++;
    }
    // 如果溢出，强转成 int 就会和真实值不同
    if (res > 2147483647) {
        return sign === 1 ? 2147483647 : -2147483648; // Integer.MAX_VALUE : Integer.MIN_VALUE
    }
    return res * sign;
};
```

</div></div>
</div></div>

<hr /><details open hint-container details><summary style="font-size: medium"><strong>🥳🥳 算法可视化 🥳🥳</strong></summary><div id="data_string-to-integer-atoi"  category="leetcode" ></div><div class="resizable aspect-ratio-container" style="height: 100%;">
<div id="iframe_string-to-integer-atoi"></div></div>
</details><hr /><br />

</div>
</details>
</div>

