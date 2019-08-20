/**
 * 函数查询网站
 *     pubs.opengroup.org
 *     linux.die.net
 *     man7.org
 */

/**
 * @brief
 *     包含于<stdio.h> 
 *     从stdin流中读取字符串，直到遇到换行符或者EOF时停止，换行符不会被写入字符串。
 * 
 * @param  str 指针（char数组的头地址），用来存储字符串
 * 
 * @retval char *
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
 * @param  str    指针（char数组的头地址），用来存储字符串
 * @param  num    最大读取字符数，包括最后的空字符('\0')
 * @param  stream 指向定义了输入流的FILE对象的指针，可以使用 stdin 从标准输入流中读取数据
 * 
 * @retval char *
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
 * @param  format c字符串，格式化说明符
 * @param  ...    保存读入值的参数列表
 *
 * @retval int
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
 * @param  cmd 指定函数要执行的操作，有效的cmd值被定义在<fcntl.h>中
 * @param  ... 根据cmd的不同，参数不同
 *
 * @retval int
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
 * @param  buffer 指向一个字符数组，存储读取到的字符串
 * @param  n      最多读取的字符数+1
 * 
 * @retval int
 *     成功返回str
 *     失败返回null
 */
char *gets_s(char *buffer, rsize_t n);

/**
 * @brief
 *     包含于<stat.h>
 *     返回文件信息
 *     
 * @param  path 文件路径
 * @param  buf  存储文件信息的结构体
 * 
 * @retval int
 *     成功返回0
 *     失败返回-1，并设置errno
 */
int stat(const char *path, struct stat *buf);

/**
 * @brief
 *     包含于<stdio.h>
 *     返回文件信息
 *     当 path 为符号链接时，返回符号链接本身的信息，stat()返回链接指向的文件的信息
 *     其他情况与stat()相同.
 *     
 * @param  path 文件路径
 * @param  buf  存储文件信息的结构体
 * 
 * @return int
 *     成功返回0
 *     失败返回-1，并设置errno
 */
int lstat(const char *path, struct stat *buf);

/**
 * @brief
 *     包含于<stdio.h>
 *     返回文件信息
 *     与stat()相同，但要检索的文件由文件描述符fildes指定.
 *     
 * @param  fildes 文件描述符
 * @param  buf    存储文件信息的结构体
 * 
 * @return int
 *     成功返回0
 *     失败返回-1，并设置errno
 */
int fstat(int fildes, struct stat *buf);

/**
 * @brief
 *     打开一个由path指向的目录
 *     
 * @param  path 目录的路径
 * 
 * @return DIR *
 *     如果成功，返回该目录流的指针
 *     如果发生错误，返回NULL，并设置errno
 */
DIR *opendir(const char *path);

/**
 * @brief
 *     读取由dirp指向的目录流
 *     
 * @param  dirp 指向目录的DIR指针
 * 
 * @return struct dirent *
 *     如果成功，返回该目录的drient结构体指针（该结构体可能会静态分配，不要尝试去free()）
 *     如果达到流末尾，返回NULL
 *     如果发生错误，返回NULL，并设置errno
 */
struct dirent *readdir(DIR *dirp);

/**
 * @brief
 *     关闭目录，成功调用closedir()后，该目录潜在的文件描述符也会被关闭
 *     dirp在函数被调用后将不可用
 *     
 * @param  dirp 指向目录的DIR指针
 * 
 * @return int
 *     成功返回0
 *     失败返回-1，并设置errno
 */
int closedir(DIR *dirp);

/**
 * @brief
 *     包含于<unidt.h> 系统调用
 *     从文件描述符 fd 指定的文件中，读取 count 字节的数据到 buf 指向的缓冲区
 *
 * @param  fd    文件描述符
 * @param  buf   缓冲区
 * @param  count 最多读取的字节数
 *
 * @return ssize_t
 *     成功返回读取的字节数，0 表示文件结束，文件操作指针将按照这个数字提前
 *     失败返回-1，并设置errno，此时，无法确定文件操作指针（如果有）是否改变
 */
ssize_t read(int fd, void *buf, size_t count);

/**
 * @brief
 *     包含于<unidt.h> 系统调用
 *     将 buf 指向的缓冲区中 count 字节的数据写入到文件描述符 fd 指定的文件中
 * 
 * @param  fd    文件描述符
 * @param  buf   缓冲区
 * @param  count 最多写入的大小
 *
 * @return ssize_t
 *     成功返回写入的字节数
 *     失败返回-1，并设置errno
 *     如果 count 为 0 ，且 fd 指向的是正常的文件，
 *         如果函数发生错误，则返回错误状态
 *         如果没有错误，则什么也不发生
 *     如果 count 为 0 ，且 fd 指向非常规文件
 *         则结果不能确定
 */     
ssize_t write(int fd, const void *buf, size_t count);