# 8.1 原型继承：  
  # 8.1.1
    [[Prototype]]：
      在 JavaScript 中，对象有一个特殊的隐藏属性 [[Prototype]]（如规范中所命名的），它要么为 null，要么就是对另一个对象的引用。
        该对象被称为“原型”（指的是引用的对象）。
      当我们从 object 中读取一个缺失的属性时，JavaScript 会自动从原型中获取该属性。在编程中，这被称为“原型继承”。
      设置方法：（之一）
        obj1.__proto__ = obj2;
      （注：原型链可以很长；
        一个对象的__proto__对象只有一个。
        注意，__proto__的使用有两个限制：
          1. 引用不能形成闭环。如果我们试图在一个闭环中分配 __proto__，JavaScript 会抛出错误。
          2. __proto__ 的值可以是对象，也可以是 null。而其他的类型都会被忽略。）
      （__proto__ 是 [[Prototype]] 的因历史原因而留下来的 getter/setter，所以__proto__ 和 [[Prototype]] 这两个并不相同）
  # 8.1.2
    写入不使用原型：
      原型仅用于读取属性。
      （注：访问器（accessor）属性是一个例外，其在写入/删除时不会改变“原型”本身的值）
      对于写入/删除操作可以直接在对象上进行。
  # 8.1.3
    “this” 的值；
      无论在哪里找到方法：在一个对象还是在原型中。在一个方法调用中，this 始终是点符号 . 前面的对象。（不受原型的影响）
  # 8.1.4
    for…in 循环：
      for..in 会遍历自己以及继承的键 // 按照继承链出现
      （注：Object.keys 只返回自己的 key）
      //  obj.hasOwnProperty(key) 可以判断 key 属性是否存在，返回一个布尔值
      （注意！几乎所有其他键/值获取方法都忽略继承的属性）
# 一些总结： https://zh.javascript.info/prototype-inheritance#zong-jie