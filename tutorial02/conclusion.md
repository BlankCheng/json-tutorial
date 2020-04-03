## 任务
1. 重构合并 lept_parse_null()、lept_parse_false()、lept_parse_true 为 lept_parse_literal()。
2. 加入 维基百科双精度浮点数 的一些边界值至单元测试，如 min subnormal positive double、max double 等。
3. 去掉 test_parse_invalid_value() 和 test_parse_root_not_singular 中的 #if 0 ... #endif，执行测试，证实测试失败。按 JSON number 的语法在 lept_parse_number() 校验，不符合标准的程况返回LEPT_PARSE_INVALID_VALUE　错误码。
4. 去掉 test_parse_number_too_big 中的 #if 0 ... #endif，执行测试，证实测试失败。仔细阅读 strtod()，看看怎样从返回值得知数值是否过大，以返回 LEPT_PARSE_NUMBER_TOO_BIG 错误码。（提示：这里需要 #include 额外两个标准库头文件。

## 总结
1. lept_parse_literal可以把null, true, false作为参数literal输入
2. 参考IEEE标准，浮点数的上下界，和指数有关(没有研究)
3. 我写的非常tricky，完全针对给出的test case写if else，但是可读性较差。参考答案用指针p遍历，valid就p++。寻找标志'.'、'eE'，若标志后面不满足立刻返回invalid。总结下来，标志的后一个必须是数字。
4. 当errno==ERANGE,说明出了问题。可以判断结果是否维HIGH_VAL,-HIGH_VAL
