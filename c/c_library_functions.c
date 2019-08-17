/**
 * @brief
 *      从stdin流中读取字符串，直到遇到换行符或者EOF时停止，换行符不会被
 *      写入字符串。
 * 
 * @param str 指针（char数组的头地址），用来存储字符串
 * 
 * @retval
 *      成功执行返回str
 *      如果遇到end-of-file，设置feof标志
 *      如果读取过程发生错误，设置ferror标志，返回null指针
 *
 * @note
 *      可以无限读取，内存不安全，C11已移除，使用fgets()代替
 */
char *gets(char *str);

/**
 * @brief
 *      从steam中读取字符串，并存储在str中，当读取数达到num或者遇到换行符时结束
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
 *      从标准流中读取格式化输入
 *
 * @param format c字符串，格式化说明符
 *
 * @retval
 *      如果成功，返回成功读取个数
 *      如果遇到EOF或者读取失败，返回EOF，设置适当的标志(feof或者ferror)
 *      如果解析宽字符时发生编码错误，则将errno设置为EILSEQ
 */
int scanf(const char *format, ...);