#include "headers.h"

SmbOpTableEntry smboptable[256] = {
[SMB_COM_CREATE_DIRECTORY] { "SMB_COM_CREATE_DIRECTORY", smbcomcreatedirectory },
[SMB_COM_DELETE_DIRECTORY] { "SMB_COM_DELETE_DIRECTORY", smbcomdeletedirectory },
[SMB_COM_OPEN] { "SMB_COM_OPEN", smbcomopen },
[SMB_COM_CREATE] { "SMB_COM_CREATE", smbcomcreate },
[SMB_COM_CLOSE] { "SMB_COM_CLOSE", smbcomclose },
[SMB_COM_FLUSH] { "SMB_COM_FLUSH", smbcomflush },
[SMB_COM_DELETE] { "SMB_COM_DELETE", smbcomdelete },
[SMB_COM_RENAME] { "SMB_COM_RENAME", smbcomrename },
[SMB_COM_QUERY_INFORMATION] { "SMB_COM_QUERY_INFORMATION", smbcomqueryinformation },
[SMB_COM_SET_INFORMATION] { "SMB_COM_SET_INFORMATION", smbcomsetinformation },
[SMB_COM_READ] { "SMB_COM_READ", nil },
[SMB_COM_WRITE] { "SMB_COM_WRITE", smbcomwrite },
[SMB_COM_LOCK_BYTE_RANGE] { "SMB_COM_LOCK_BYTE_RANGE", nil },
[SMB_COM_UNLOCK_BYTE_RANGE] { "SMB_COM_UNLOCK_BYTE_RANGE", nil },
[SMB_COM_CREATE_TEMPORARY] { "SMB_COM_CREATE_TEMPORARY", nil },
[SMB_COM_CREATE_NEW] { "SMB_COM_CREATE_NEW", nil },
[SMB_COM_CHECK_DIRECTORY] { "SMB_COM_CHECK_DIRECTORY", smbcomcheckdirectory },
[SMB_COM_PROCESS_EXIT] { "SMB_COM_PROCESS_EXIT", nil },
[SMB_COM_SEEK] { "SMB_COM_SEEK", nil },
[SMB_COM_LOCK_AND_READ] { "SMB_COM_LOCK_AND_READ", nil },
[SMB_COM_WRITE_AND_UNLOCK] { "SMB_COM_WRITE_AND_UNLOCK", nil },
[SMB_COM_READ_RAW] { "SMB_COM_READ_RAW", nil },
[SMB_COM_READ_MPX] { "SMB_COM_READ_MPX", nil },
[SMB_COM_READ_MPX_SECONDARY] { "SMB_COM_READ_MPX_SECONDARY", nil },
[SMB_COM_WRITE_RAW] { "SMB_COM_WRITE_RAW", nil },
[SMB_COM_WRITE_MPX] { "SMB_COM_WRITE_MPX", nil },
[SMB_COM_WRITE_MPX_SECONDARY] { "SMB_COM_WRITE_MPX_SECONDARY", nil },
[SMB_COM_WRITE_COMPLETE] { "SMB_COM_WRITE_COMPLETE", nil },
[SMB_COM_QUERY_SERVER] { "SMB_COM_QUERY_SERVER", nil },
[SMB_COM_SET_INFORMATION2] { "SMB_COM_SET_INFORMATION2", smbcomsetinformation2 },
[SMB_COM_QUERY_INFORMATION2] { "SMB_COM_QUERY_INFORMATION2", smbcomqueryinformation2 },
[SMB_COM_LOCKING_ANDX] { "SMB_COM_LOCKING_ANDX", smbcomlockingandx },
[SMB_COM_TRANSACTION] { "SMB_COM_TRANSACTION", smbcomtransaction },
[SMB_COM_TRANSACTION_SECONDARY] { "SMB_COM_TRANSACTION_SECONDARY", nil },
[SMB_COM_IOCTL] { "SMB_COM_IOCTL", nil },
[SMB_COM_IOCTL_SECONDARY] { "SMB_COM_IOCTL_SECONDARY", nil },
[SMB_COM_COPY] { "SMB_COM_COPY", nil },
[SMB_COM_MOVE] { "SMB_COM_MOVE", nil },
[SMB_COM_ECHO] { "SMB_COM_ECHO", smbcomecho },
[SMB_COM_WRITE_AND_CLOSE] { "SMB_COM_WRITE_AND_CLOSE", nil },
[SMB_COM_OPEN_ANDX] { "SMB_COM_OPEN_ANDX", smbcomopenandx },
[SMB_COM_READ_ANDX] { "SMB_COM_READ_ANDX", smbcomreadandx },
[SMB_COM_WRITE_ANDX] { "SMB_COM_WRITE_ANDX", smbcomwriteandx },
[SMB_COM_NEW_FILE_SIZE] { "SMB_COM_NEW_FILE_SIZE", nil },
[SMB_COM_CLOSE_AND_TREE_DISC] { "SMB_COM_CLOSE_AND_TREE_DISC", nil },
[SMB_COM_TRANSACTION2] { "SMB_COM_TRANSACTION2", smbcomtransaction2 },
[SMB_COM_TRANSACTION2_SECONDARY] { "SMB_COM_TRANSACTION2_SECONDARY", nil },
[SMB_COM_FIND_CLOSE2] { "SMB_COM_FIND_CLOSE2", smbcomfindclose2 },
[SMB_COM_FIND_NOTIFY_CLOSE] { "SMB_COM_FIND_NOTIFY_CLOSE", nil },
[SMB_COM_TREE_CONNECT] { "SMB_COM_TREE_CONNECT", nil },
[SMB_COM_TREE_DISCONNECT] { "SMB_COM_TREE_DISCONNECT", smbcomtreedisconnect },
[SMB_COM_NEGOTIATE] { "SMB_COM_NEGOTIATE", smbnegotiate },
[SMB_COM_SESSION_SETUP_ANDX] { "SMB_COM_SESSION_SETUP_ANDX", smbcomsessionsetupandx },
[SMB_COM_LOGOFF_ANDX] { "SMB_COM_LOGOFF_ANDX", nil },
[SMB_COM_TREE_CONNECT_ANDX] { "SMB_COM_TREE_CONNECT_ANDX", smbcomtreeconnectandx },
[SMB_COM_QUERY_INFORMATION_DISK] { "SMB_COM_QUERY_INFORMATION_DISK", nil },
[SMB_COM_SEARCH] { "SMB_COM_SEARCH", nil },
[SMB_COM_FIND] { "SMB_COM_FIND", nil },
[SMB_COM_FIND_UNIQUE] { "SMB_COM_FIND_UNIQUE", nil },
[SMB_COM_FIND_CLOSE] { "SMB_COM_FIND_CLOSE", nil },
[SMB_COM_NT_TRANSACT] { "SMB_COM_NT_TRANSACT", nil },
[SMB_COM_NT_TRANSACT_SECONDARY] { "SMB_COM_NT_TRANSACT_SECONDARY", nil },
[SMB_COM_NT_CREATE_ANDX] { "SMB_COM_NT_CREATE_ANDX", smbcomntcreateandx },
[SMB_COM_NT_CANCEL] { "SMB_COM_NT_CANCEL", nil },
[SMB_COM_NT_RENAME] { "SMB_COM_NT_RENAME", nil },
[SMB_COM_OPEN_PRINT_FILE] { "SMB_COM_OPEN_PRINT_FILE", nil },
[SMB_COM_WRITE_PRINT_FILE] { "SMB_COM_WRITE_PRINT_FILE", nil },
[SMB_COM_CLOSE_PRINT_FILE] { "SMB_COM_CLOSE_PRINT_FILE", nil },
[SMB_COM_GET_PRINT_QUEUE] { "SMB_COM_GET_PRINT_QUEUE", nil },
[SMB_COM_READ_BULK] { "SMB_COM_READ_BULK", nil },
[SMB_COM_WRITE_BULK] { "SMB_COM_WRITE_BULK", nil },
[SMB_COM_NO_ANDX_COMMAND] { "SMB_COM_NO_ANDX_COMMAND", nil },
};

SmbTrans2OpTableEntry
smbtrans2optable[] = {
[SMB_TRANS2_OPEN] { "SMB_TRANS2_OPEN", nil },
[SMB_TRANS2_FIND_FIRST2] { "SMB_TRANS2_FIND_FIRST2", smbtrans2findfirst2 },
[SMB_TRANS2_FIND_NEXT2] { "SMB_TRANS2_FIND_NEXT2", smbtrans2findnext2 },
[SMB_TRANS2_QUERY_FS_INFORMATION] { "SMB_TRANS2_QUERY_FS_INFORMATION", smbtrans2queryfsinformation },
[SMB_TRANS2_SET_FS_INFORMATION] { "SMB_TRANS2_SET_FS_INFORMATION", nil },
[SMB_TRANS2_QUERY_PATH_INFORMATION] { "SMB_TRANS2_QUERY_PATH_INFORMATION", smbtrans2querypathinformation },
[SMB_TRANS2_SET_PATH_INFORMATION] { "SMB_TRANS2_SET_PATH_INFORMATION", smbtrans2setpathinformation },
[SMB_TRANS2_QUERY_FILE_INFORMATION] { "SMB_TRANS2_QUERY_FILE_INFORMATION", smbtrans2queryfileinformation },
[SMB_TRANS2_SET_FILE_INFORMATION] { "SMB_TRANS2_SET_FILE_INFORMATION", smbtrans2setfileinformation },
[SMB_TRANS2_FSCTL] { "SMB_TRANS2_FSCTL", nil },
[SMB_TRANS2_IOCTL2] { "SMB_TRANS2_IOCTL2", nil },
[SMB_TRANS2_FIND_NOTIFY_FIRST] { "SMB_TRANS2_FIND_NOTIFY_FIRST", nil },
[SMB_TRANS2_FIND_NOTIFY_NEXT] { "SMB_TRANS2_FIND_NOTIFY_NEXT", nil },
[SMB_TRANS2_CREATE_DIRECTORY] { "SMB_TRANS2_CREATE_DIRECTORY", nil },
[SMB_TRANS2_SESSION_SETUP] { "SMB_TRANS2_SESSION_SETUP", nil },
[SMB_TRANS2_GET_DFS_REFERRAL] { "SMB_TRANS2_GET_DFS_REFERRAL", nil },
[SMB_TRANS2_REPORT_DFS_INCONSISTENCY] { "SMB_TRANS2_REPORT_DFS_INCONSISTENCY", nil },
};
int smbtrans2optablesize = nelem(smbtrans2optable);
