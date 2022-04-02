syscall::open:entry
/gid==$1/
{	
	printf("gid:%d, executable:%s, pid:%d, uid:%d, %s:%s",gid,execname,pid,uid,probefunc,copyinstr(arg0));
	printf("\n----------------------------------------------------\n");
}

syscall::access:entry
/gid==$1/
{	
	printf("executable:%s, pid:%d, uid:%d, %s:%s",execname,pid,uid,probefunc,copyinstr(arg0));
	printf("\n----------------------------------------------------\n");
}

proc:::exec
/gid==$1/
{	
	printf("%s",stringof(args[0]));
	printf("\n----------------------------------------------------\n");
}

proc:::exit
/gid==$1/
{	
	printf("%d",args[0]);
	printf("\n----------------------------------------------------\n");
}

syscall::read:entry, syscall::write:entry
/gid==$1 && execname!="sh"/
{
	ts[probefunc] = timestamp;
	printf("exec:%s", execname);
	printf("\n----------------------------------------------------\n");

}

syscall::read:return, syscall::write:return
/gid == $1 && ts[probefunc] != 0 && execname!="sh"/
{
	printf("%d nanoseconds", timestamp - ts[probefunc]);
	printf("\n----------------------------------------------------\n");
}

syscall:::entry
/gid==$1/
{
	@syscalls[probefunc]=count();
}
