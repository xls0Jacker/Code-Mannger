# 2.6.1
    交互：（以下为几条样例）
    1. alert:
        它会显示一条信息，并等待用户按下 “OK”。
        （弹出的这个带有信息的小窗口被称为 模态窗。）
        //意味着用户不能与页面的其他部分（例如点击其他按钮等）进行交互，直到他们处理完窗口。
        语法：
            alert("Hello");
            （alert 的返回值为 undefined）
    2. prompt：
        其接收两个参数：
        形如：prompt(title, [default])，//同样是一个 模态窗
            title是显示的文本内容；
            default是input的内容。
            （上述语法中 default 周围的方括号表示该参数是可选的，不是必需的。）//可选的 就是第二个参数可以不写
        （Internet Explorer 会把 "undefined" 插入到 prompt。所以，为了 prompt 在 IE 中有好的效果，我们建议始终提供第二个参数：）
        语法：
            result = prompt(title, [default]);
            （按下Esc键返回null）
            //prompt 以字符串的形式返回用户的输入。
    3. confirm：
        它显示一个带有 question 以及确定和取消两个按钮的模态窗口。
        点击确定返回 true，点击取消返回 false。
        语法：
            result = confirm(question);
            （按下Esc键返回false）
# 一些总结： https://zh.javascript.info/alert-prompt-confirm#zong-jie
