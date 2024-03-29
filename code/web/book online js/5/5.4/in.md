# 5.4 数组：
  数组可以存储任何类型的元素。// 可以多种不同类型放在同一数组
  # 5.4.1 
    声明：
      语法：  
        let arr = new Array();
        let arr = [];
        （绝大多数情况下使用第二种方案）
      数组元素从 0 开始编号。
        我们可以通过方括号中的数字获取元素
          或者向数组新加一个元素。
      length 属性的值是数组中元素的总个数
      以用 alert 来显示整个数组。
      Ex 数组就像对象一样，可以以逗号结尾
  # 5.4.2
    使用 “at” 获取最后一个元素：  
      JavaScript 中不允许出现负数的索引，
        因此出现了一个方法：  
          arr.at(i)：
          如果 i >= 0，则与 arr[i] 完全相同。
          对于 i 为负数的情况，它则从数组的尾部向前数。
  # 5.4.3
    pop/push, shift/unshift 方法：  
      pop 取出并返回数组的最后一个元素；
      push 在数组末端添加元素；
      shift 取出数组的第一个元素并返回它；  
      unshift 在数组的首端添加元素
      （push 和 unshift 方法都可以一次添加多个元素）
  # 5.4.4
    内部：
      数组从本质上来讲是一个一个一个对象。
      数组误用的几种方式:
        1. 添加一个非数组的属性，比如 arr.test = 5。
        2. 制造空洞，比如：添加 arr[0]，然后添加 arr[1000] (它们中间什么都没有)。
        3. 以倒序填充数组，比如 arr[1000]，arr[999] 等等。
  # 5.4.6
    性能：  
      作用于数组的末端会比首端快。
  # 5.4.7
    循环：  
      遍历数组最古老的方式就是 for 循环；
      另一种循环方式：
        for..of
        获取数组中的元素值，不返回其索引
        （技术上来讲，因为数组也是对象，所以使用 for..in 也是可以的，但是其会打出其他的属性，所以不建议）
  # 5.4.8
    关于 “length”： 
      当我们修改数组的时候，length 属性会自动更新。
      length 属性是可写的：
        如果我们手动增加它，则不会发生任何事。
          但是如果我们减少它，数组就会被截断。
          （注意！该过程是不可逆的）
  # 5.4.9
    new Array()： 
      如果使用单个参数（即数字）调用 new Array，那么它会创建一个 指定了长度，却没有任何项 的数组。
      为了避免这种意外情况，我们通常使用方括号，除非我们真的知道自己在做什么。
  # 5.4.10
    多维数组：  
      数组里的项也可以是数组。
  # 5.4.11
    toString：
      数组有自己的 toString 方法的实现，会返回以逗号隔开的元素列表。
  # 5.4.12
    不要使用 == 比较数组。
    如果我们使用 == 来比较数组，除非我们比较的是两个引用同一数组的变量，否则它们永远不相等。
    与原始类型的比较时数组会自动调用 toString 方法后进行比较。
# 一些总结： https://zh.javascript.info/array#zong-jie
