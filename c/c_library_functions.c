/**
 * @brief
 *     包含于<stdio.h> 
 *     从stdin流中读取字符串，直到遇到换行符或者EOF时停止，换行符不会被写入字符串。
 * 
 * @param str 指针（char数组的头地址），用来存储字符串
 * 
 * @retval
 *      成功执行返回str
 *      如果遇到end-of-file，设置feof标志
 *      如果读取过程发生错误，设置ferror标志，返回null指针
 *     
 * @note
 *      可以无限读取，内存不安全，在ISO/IEC 9899 2011(C11) 标准中被移除，使用fgets()代替
 */
char *gets(char *str);

/**
 * @brief
 *     包含于<stdio.h>
 *     从steam中读取字符串，并存储在str中，当读取数达到 num-1 或者遇到换行符时结束
 *     fgets()会存储读取到的换行符
 *      
 * @param str    指针（char数组的头地址），用来存储字符串
 * @param num    最大读取字符数，包括最后的空字符('\0')
 * @param stream 指向定义了输入流的FILE对象的指针，可以使用 stdin 从标准输入流中读取数据
 * 
 * @retval
 *      如果成功，返回str
 *      如果遇到end-of-file，设置feof标志
 *      如果读取过程发生错误，设置ferror标志，返回null指针
 */
char *fgets(char *str, int num, FILE *stream);

/**
 * @brief
 *     包含于<stdio.h>     
 *     从标准流中读取格式化输入
 *
 * @param format c字符串，格式化说明符
 * @param ...    保存读入值的参数列表
 *
 * @retval
 *      如果成功，返回成功读取个数
 *      如果遇到EOF或者读取失败，返回EOF，设置适当的标志(feof或者ferror)
 *      如果解析宽字符时发生编码错误，则将errno设置为EILSEQ
 */
int scanf(const char *format, ...);

/**
 * @brief
 *     包含于<unistd.h>
 *     文件控制，根据cmd参数执行操作
 *
 * @param cmd 指定函数要执行的操作，有效的cmd值被定义在<fcntl.h>中
 * @param ... 根据cmd的不同，参数不同
 *
 * @retval
 *     如果失败，返回-1
 *     成功返回-1以外的值
 */
int fcntl(int fildes, int cmd, ...);

/**
 * @brief
 *     包含于<stdio.h>
 *     从标准流中读取字符串，直到遇到换行符或者EOF标志，最多读取 n-1 个字符，换行符不会被存储.
 *     改函数会在最后写入'\0'结束符
 * 
 * @param buffer 指向一个字符数组，存储读取到的字符串
 * @param n      最多读取的字符数+1
 * 
 * @retval
 *     成功返回str
 *     失败返回null
 */
char *gets_s(char *buffer, rsize_t n);
