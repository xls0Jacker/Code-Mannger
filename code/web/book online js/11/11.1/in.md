# 11.1 简介：回调( callback )：
   异步行为：  
    我们现在开始执行的行为，但它们会在稍后完成。
  // 使先执行一个script内容，之后再执行本来的内容。
  # 11.1.1
    在回调中回调：
      如何依次加载多个脚本？
        嵌套即可。
  # 11.1.2
    处理 Error：
      callback 的第一个参数是为 error 而保留的。一旦出现 error，callback(err) 就会被调用。
      第二个参数（和下一个参数，如果需要的话）用于成功的结果。此时 callback(null, result1, result2…) 就会被调用。
      // 单一的 callback 函数可以同时具有报告 error 和传递返回结果的作用
  # 11.1.3
    厄运金字塔：
      多层的嵌套会导致难以操作。// 其嵌套所形成形状类似于塔尖向右的金字塔，故称为“回调地狱”或“厄运金字塔”
        可以通过使每个行为都成为一个独立的函数来尝试减轻这种问题。