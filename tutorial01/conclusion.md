## 任务
1. 修正关于 LEPT_PARSE_ROOT_NOT_SINGULAR 的单元测试，若 json 在一个值之后，空白之后还有其它字符，则要返回 LEPT_PARSE_ROOT_NOT_SINGULAR。
2. 参考 test_parse_null()，加入 test_parse_true()、test_parse_false() 单元测试。
3. 参考 lept_parse_null() 的实现和调用方，解析 true 和 false 值。

## 总结
我对第一个任务的实现，没有利用lept_parse_whitespaces这个已有函数。可以在lept_parse_value之后再次调用lept_parse_whitespaces，看指针是否指向'\0'。