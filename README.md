# EZLOG Library

A Simple library that provides basic logging functionality.
EZLog can be easily integrated into your projects with minimal efforts.


## Example:

```C
#include <ezlog.h>

int main(void)
{
	EZLOGD("This is Debug\n");
	EZLOGI("This is Info\n");
	EZLOGW("This is Warning\n");
	EZLOGE("This is Error\n");

	return 0;
}
```
Output:
<pre>
<font color="green">[DEBUG] This is Debug</font>
<font color="blue">[INFO] This is Info</font>
<font color="orange">[WARN] This is Warning</font>
<font color="red">[ERROR] This is Error</font>
</pre>
