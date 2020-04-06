## 任务
1. 编写 lept_get_boolean() 等访问函数的单元测试，然后实现。
2. 实现除了 \u 以外的转义序列解析，令 test_parse_string() 中所有测试通过。
3. 解决 test_parse_invalid_string_escape() 和 test_parse_invalid_string_char() 中的失败测试。
4. 思考如何优化 lept_parse_string() 的性能，那些优化方法有没有缺点。

## 总结
+ 如果要打印转义字符，原字符串的转义字符前要加上\\。json中的是raw格式，parse成C语言中的转义字符格式。json中出现\\w这种parse后无对应的转义，这里判为invalid。
换句话说，在json中出现\\一定表示后面要有转义的字符出现，否则就invalid。
+ invalid char是json字符中绝对禁止的字符。不太明白，用x20类似的八进制来表示字符？