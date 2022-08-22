# 2.1.1
    “script” 标签：我们几乎可以使用 <script> 标签将 JavaScript 程序插入到 HTML 文档的任何位置。
# 2.1.2
    现代的标记（markup）：HTML4规范中的古老标记如下
        <script type="text/javascript"><!--
        ...
        //--></script>
# 2.1.3
    外部脚本：如果你有大量的 JavaScript 代码，我们可以将它放入一个单独的文件。
        脚本文件可以通过 src 特性（attribute）添加到 HTML 文件中。
        绝对路径从网站根目录开始的绝对路径，当前页面的相对路径，一个完整的 URL 地址 均可
        （好处是可以让页面提前缓存提升用户体验）
        （需要注意的是通过 src 特性添加到 HTML 文件中的代码无法进行 script 的操作）//需拆成两个标签
# 一些总结： https://zh.javascript.info/hello-world#zong-jie