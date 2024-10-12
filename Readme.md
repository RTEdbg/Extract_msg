# Extract_msg - processing of the messages.h file for the compilation process of the RTEmsg utility

This is a helper utility for the compilation process of  the [**RTEmsg utility**](https://github.com/RTEdbg/RTEmsg). It is included in the RTEdbg toolkit distribution package - see the "c:\RTEdbg\UTIL" folder.

The RTEmsg software application uses Messages.txt file for texts used when writing messages with printf or fprintf. These are normal messages, error messages, warnings, and the like. In the prebuild phase of translation, the the messages.h header file is scanned with the Extract_msg utility and converted to Messages.txt (contains raw text messages).

Using an external text file allows easy translation from English to other languages. The translated Messages.txt file must be in UTF-8 format.

## How to Contribute or Get Help
Follow the **[Contributing Guidelines](https://github.com/RTEdbg/RTEdbg/blob/master/docs/CONTRIBUTING.md)** for bug reports and feature requests. When asking a support question, be clear and take the time to explain your problem properly. Please use **[RTEdbg.freeforums.net](https://rtedbg.freeforums.net/)** for general discussions about **[RTEdbg toolkit](https://github.com/RTEdbg/RTEdbg)**. If your problem is not strictly related to this project, we recommend that you use **[Stack Overflow](https://stackoverflow.com/)** or similar forum instead.
