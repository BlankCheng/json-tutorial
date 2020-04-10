## 任务
1. 编写 test_parse_array() 单元测试，解析以下 2 个 JSON。由于数组是复合的类型，不能使用一个宏去测试结果，请使用各个 API 检查解析后的内容。
[ null , false , true , 123 , "abc" ]
[ [ ] , [ 0 ] , [ 0 , 1 ] , [ 0 , 1 , 2 ] ]
2. 现时的测试结果应该是失败的，因为 lept_parse_array() 里没有处理空白字符，加进合适的lept_parse_whitespace() 令测试通过。
3. 使用第三单元解答篇介绍的检测内存泄漏工具，会发现测试中有内存泄漏。很明显在 lept_parse_array() 中使用到malloc() 分配内存，但却没有对应的 free()。应该在哪里释放内存？修改代码，使工具不再检测到相关的内存泄漏。
4. 开启 test.c 中两处被 #if 0 ... #endif 关闭的测试，本来 test_parse_array() 已经能处理这些测试。然而，运行时会发现 Assertion failed: (c.top == 0) 断言失败。这是由于，当错误发生时，仍然有一些临时值在堆栈里，既没有放进数组，也没有被释放。修改 test_parse_array()，当遇到错误时，从堆栈中弹出并释放那些临时值，然后才返回错误码。
5. 第 4 节那段代码为什么会有 bug？


## 总结
1. 熟练使用不同类型的get API和test宏。
2. 在lept_parse_value前后各用一次lept_parse_whitespace。
3. v->u.a.e需要释放。这里我直接free(v->u.a.e)是错误的，需要递归地释放其中每个元素，因为元素可能是lept_string或者lept_array，也需要释放。 
4. lept_context_pop()弹出。这里也需要用lept_free，因为之前压入的元素可能需要释放，而不只是改top指针。
5. 每次stack扩容后c->stack首地址就会改变，所以不能这样。

