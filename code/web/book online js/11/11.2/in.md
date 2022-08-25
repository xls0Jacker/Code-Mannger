# 11.2 Promise：
  语法： 
    let promise = new Promise(function(resolve, reject) {
      // executor（生产者代码，“歌手”）
    });
      传递给 new Promise 的函数被称为 executor。当 new Promise 被创建，executor 会自动运行。
      参数 resolve 和 reject 是由 JavaScript 自身提供的回调。我们的代码仅在 executor 的内部。
  executor 执行成功则调用 resolve ，执行 error 则调用 reject。

  promise 存在三种状态：
    pending, //等待中 （未处理）
    fullfilled, // executor 处理为 resolve
    reject // excutor 处理为 error
  
  （注：只能有一个结果或一个 error；
    以 Error 对象 reject；
      resolve/reject 可以立即进行；
        state 和 result 都是内部的）
  # 11.2.1
    消费者：then，catch：
      then：
        语法：
        promise.then(
          function(result) { /* handle a successful result */ },
          function(error) { /* handle an error */ }
        );
          .then 的第一个参数是一个函数，该函数将在 promise resolved 且接收到结果后执行。
          .then 的第二个参数也是一个函数，该函数将在 promise rejected 且接收到 error 信息后执行。
        如果我们只对成功完成的情况感兴趣，那么我们可以只为 .then 提供一个函数参数；
        如果我们只对 error 感兴趣，那么我们可以使用 null 作为第一个参数。
      catch：
        同样当我们只对 error 感兴趣时，也可以使用 .catch(errorHandlingFunction)。
        // .catch(f) 调用是 .then(null, f) 的完全的模拟，它只是一个简写形式。
  # 11.2.2
    清理：finally；
      调用 .finally(f) 类似于 .then(f, f)，因为当 promise settled 时 f 就会执行：无论 promise 被 resolve 还是 reject。
      // 即无论结果均实现
      finally 的功能是设置一个处理程序在前面的操作完成后，执行清理/终结。
      // 我们可以对 settled 的 promise 附加处理程序
  # 11.2.3
    示例：loadScript：
      略。

