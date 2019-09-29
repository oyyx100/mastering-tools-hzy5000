#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/types.h>
#include<linux/slab.h>
struct birthday{
	int day;
	int month;
	int year;
	struct list_head list;
};
void list_insert(struct list_head *head,int year,int month,int day){
        struct birthday *n;
        n=kmalloc(sizeof(*n),GFP_KERNEL);
        n->year=year;
        n->month=month;
        n->day=day;
        INIT_LIST_HEAD(&n->list);
        list_add_tail(&n->list,head);
}

int birthday_init(void){
	printk(KERN_INFO "Loading Module\n");
	static LIST_HEAD(birthday_list);
	list_insert(&birthday_list,2000,10,10);
	list_insert(&birthday_list,2000,10,11);
	list_insert(&birthday_list,2000,10,12);
	list_insert(&birthday_list,2000,10,13);
	list_insert(&birthday_list,2000,10,14);
	struct birthday *p;
	list_for_each_entry(p,&birthday_list,list){
	printk("%d\t%d\t%d\n",p->year,p->month,p->day);
	}
	struct birthday *ptr,*next;
        list_for_each_entry_safe(ptr,next,&birthday_list,list){
        list_del(&ptr->list);
        kfree(ptr);
        }
	return 0;

}
void birthday_exit(void){
	printk(KERN_INFO "Removing Module\n");
	}

module_init(birthday_init);
module_exit(birthday_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("ZYH");

