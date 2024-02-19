#include <stdio.h> 
#include <syslog.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
int main() { 
    openlog("MyClientProgram", LOG_PID, LOG_USER | LOG_SYSLOG); // Open connection to syslog server 
     
    // Set the IP address and port of the syslog server 
    char* syslogServerIP = "192.168.10.170"; // Replace with the actual IP address of your syslog server 
    int syslogServerPort = 514; // Replace with the actual port number of your syslog server 
    
    // Alert Message
    syslog(LOG_USER | LOG_ALERT, "This is an alert message from Baban. Sent to Bhavana: %s", syslogServerIP);
    
    // Warning Message
    syslog(LOG_USER | LOG_WARNING, "This is a warning message from my client program. Sent to syslog server: %s", syslogServerIP);
    
    // Info Message
    syslog(LOG_USER | LOG_INFO, "This is an info message from my client program. Sent to syslog server: %s", syslogServerIP);
    
    closelog(); // Close connection to syslog server 
    return 0; 
}
