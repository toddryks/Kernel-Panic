#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/time.h>

MODULE_LICENSE("GPL");
static int my_date_show(struct seq_file *m, void *v) {
    struct timespec tspec;
    struct tm t;
    getnstimeofday(&tspec);
    time_to_tm(tspec.tv_sec, sys_tz.tz_minuteswest * 60 * -1, &t);
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
