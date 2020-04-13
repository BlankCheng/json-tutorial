## 任务
1. 依第 3 节所述，重构 lept_parse_string()。重构前运行单元测试，重构后确保单元测试仍保持通过。
2. 打开 test.c 中两个 #if 0，运行单元测试，证实单元测试不通过。然后实现 lept_parse_object() 中的 \todo 部分。验证实现能通过单元测试。
3. 使用工具检测内存泄漏，解决它们。

## 总结
1. 需要函数的中间变量，可以使用重构
2. 与array几乎相同
3. 我单独写了一个函数lept_free_member来释放member，但是有一个问题是lept_free_member和lept_free递归调用时并不会调用lept_free_member。更好的方法是直接在lept_free里释放k-v。