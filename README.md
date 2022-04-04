# OS_Assignment_3

5_12_25_36_37_oslabC_2.d is the file that contains the dtrace commands.

demo.c is the file that was submitted for assignment 1, and is used by dtrace to monitor in this assignment.

## Instructions To Run
* CLone this repository.
* Create four users H, S, F, A.
* Group all the newly created users into a single group called college. Make this the primary group of H, S, F and A.
* Set read and write accesses as shown below:
```
X.txt:
H:r--
S:r--
F:---
A:rw-

Y.txt:
H:r--
S:---
F:r--
A:rw-

Z.txt:
H:r--
S:---
F:---
A:rw-
```
* Open a terminal and run `./demo`.
* In a new terminal, run `dtrace -s 5_12_25_36_37_oslabC_2.d <group_id>`, where 'group_id' is the group id of college. It can be obtained by running
```
$ getent group college
```

## Team
1. CS19B012 Debeshee
2. CS19B025 Aashrith
3. CS19B036 Kranthi
4. CS19B037 Shreetesh
