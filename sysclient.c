
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
    char* syslogServerIP = "192.168.88.100"; // Replace with the actual IP address of your syslog server
    int syslogServerPort = 514; 
    // Replace with the actual port number of your syslog server
    
    // Construct the log message
    char logMessage[200];
    snprintf(logMessage, sizeof(logMessage), "This is a log message from my client program. Sent to syslog server: %s", syslogServerIP);
    
     // Alert Message
    syslog(LOG_USER | LOG_ALERT, "This is an alert message from my client program. Sent to syslog server: %s", syslogServerIP);
    
    // Warning Message
    syslog(LOG_USER | LOG_WARNING, "This is a warning message from my client program. Sent to syslog server: %s", syslogServerIP);
    
    // Info Message
    syslog(LOG_USER | LOG_INFO, "This is an info message from my client program. Sent to syslog server: %s", syslogServerIP);
    // Open a connection to the syslog server
    int logSocket = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(syslogServerPort);
    serverAddr.sin_addr.s_addr = inet_addr(syslogServerIP);
    
    // Send the log message to the specified syslog server
    sendto(logSocket, logMessage, strlen(logMessage), 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    
    closelog(); // Close connection to syslog server
    return 0;
}
