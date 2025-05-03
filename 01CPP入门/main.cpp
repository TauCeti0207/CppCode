/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-03 22:32:34
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-05-03 22:44:20
 */

#include <stdio.h>
#include <stdlib.h>
namespace yzq
{
	int scanf = 0;
	int strlen = 10;

}
int main(int argc, char const *argv[])
{
	// 默认访问的是局部或全局
	// %x打印无符号整数（unsigned int） 的十六进制表示形式（小写 a-f）。
	printf("%p\n", (void *)scanf); // 结果就是scanf函数的地址
	// 搜索scanf时是就近原则，不会到namespace里面去搜索，就近找不到就去全局搜索，头文件里找

	// 指定访问yzq空间中的
	printf("%x\n", yzq::scanf); // 0  :: 是域作用限定符
	return 0;
}