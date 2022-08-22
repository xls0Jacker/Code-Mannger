# 2.16.1
    函数表达式：
        （在 JavaScript 中，函数不是“神奇的语言结构”，而是一种特殊的值。）
        形如：
        let sayHi = function() {
            alert( "Hello" );
        };
        （注意！function 关键字后面没有函数名。函数表达式允许省略函数名。）
        （注意！函数表达式结尾有一个分号 ; ，而函数声明没有）
        匿名函数：
            这里直接在 ask(...) 调用内进行函数声明。这两个函数没有名字，所以叫 匿名函数。
            function ask(question, yes, no) {
                if (confirm(question)) yes()
                else no();
            }

            ask(
                "Do you agree?",
                function() { alert("You agreed."); },
                function() { alert("You canceled the execution."); }
            );
# 2.16.2
    函数表达式 vs 函数声明：
        函数表达式是在代码执行到达时被创建，并且仅从那一刻起可用；
        在函数声明被定义之前，它就可以被调用。
        （严格模式下，当一个函数声明在一个代码块内时，它在该代码块内的任何位置都是可见的。但在代码块外不可见。）
# 2.16.3
    什么时候选择函数声明与函数表达式？：
        绝大多数时候选择 函数声明 ，其相较而言更加灵活，可读性更高，更加醒目。//部分时候迫不得已可以使用 函数表达式
# 一些总结： https://zh.javascript.info/function-expressions#zong-jie



