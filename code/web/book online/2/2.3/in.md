# 2.3.1 
    现代模式，"use strict":为了保证旧的功能能够使用，大部分的修改是默认不生效的。你需要一个特殊的指令 —— "use strict" 来明确地激活这些特性。
    （确保 "use strict" 出现在最顶部）//只有注释可以出现在 "use strict" 的上面。
    （没有办法取消 use strict）
# 2.3.2
    浏览器控制台：将 use strict 放在代码最顶部，然后去输入多行代码。
    （控制台中可以使用 shift + Enter 组合键实现多行代码）
    （当你使用 开发者控制台 运行代码时，请注意它默认是不启动 use strict 的）
# 2.3.3
    我们应该使用 “use strict” 吗？：
        目前我们欢迎将 "use strict"; 写在脚本的顶部。稍后，当你的代码全都写在了 class 和 module 中时，你则可以将 "use strict"; 这行代码省略掉。
        （ “class” 和 “module” 它们会自动启用 use strict。因此，如果我们使用它们，则无需添加 "use strict" 指令。）
