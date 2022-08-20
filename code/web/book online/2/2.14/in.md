# 2.14.1
    "switch" 语句:
        语法：// []表示可省略部分
        switch(x) {
            case 'value1':  // if (x === 'value1')
                ...
                [break]
            case 'value2':  // if (x === 'value2')
                ...
                [break]
            default://这个可以略写
                ...
                [break]//这个属实没必要
        }
        注意！如果没有 break，程序将不经过任何检查就会继续执行下一个 case。//即之后所有的case包括default所含操作会直接执行
        （任何表达式都可以成为 switch/case 的参数）
        “case” 分组：
            将多个case连写在一起即表示分为一组。//原因是"switch" 语句无break的作用会向下一直执行直到存在break的case中。
        类型很关键：
            类型必须严格相等。（ === ）