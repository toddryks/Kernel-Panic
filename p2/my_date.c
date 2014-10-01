/* ****************************************************************
* Project 2:  System Calls, Kernel Modules & Schedulers
* Developers:  Edward Skrod, Todd Ryks
* Date:  October 2, 2014
* Part 2
* A kernel module that creates a virtual file with the current date.
* This virtual file is called currentdate. It always contains the 
* current time in the format year-month-day hour:minute:second.
**************************************************************** */

#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/time.h>     /* http://linux.die.net/include/time.h */

MODULE_LICENSE("GPL");
static int my_date_show(struct seq_file *m, void *v) {
    
    struct timespec tspec;  /* POSIX.1b structure for a time value.    */
                            /* Variables: __time_t tv_sec (seconds),   */
                            /*           long int tv_nsec (nanosecs)   */

    struct tm t;            /* Used by time functions.                 */
                            /* tm_year (Year - 1900), tm_mon (Month -1)*/
                            /* tm_mday (day), tm_hour, hours (0 - 23)  */
                            /* tm_min (minutes 0 - 59), tm_sec (0 - 60)*/

    /* Get the time of day: returned in a timespec object */
    getnstimeofday(&tspec);

    /* Convert the calendar time to the local time        */
    time_to_tm(tspec.tv_sec, sys_tz.tz_minuteswest * 60 * -1, &t);

    /*  Print the time   */
    seq_printf(m, "%ld-%02d-%02d %02d:%02d:%02d\n", t.tm_year + 1900,
            t.tm_mon + 1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec);
    return 0;
}
static int currentdate_open(struct inode *inode, struct  file *file) {
    return single_open(file, my_date_show, NULL);
}
static const struct file_operations date_proc_fops = {
    .owner = THIS_MODULE,
    .open = currentdate_open,
    .read = seq_read,
    .release = single_release,
};
static int __init my_date_init(void) {
    proc_create("currentdate", 0, NULL, &date_proc_fops);
    return 0;
}
static void __exit my_date_exit(void) {
    remove_proc_entry("currentdate", NULL);
}
module_init(my_date_init);
module_exit(my_date_exit);
