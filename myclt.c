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
    int syslogServerPort = 514; // Replace with the actual port number of your syslog server
    // Construct the log message
    char logMessage[200];
    snprintf(logMessage, sizeof(logMessage), "This is a log message from my client program. Sent to syslog server: %s", syslogServerIP);
    // Log the message using syslog function
    syslog(LOG_USER | LOG_INFO, "%s", logMessage);
    // Create a UDP socket
    int logSocket = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(syslogServerPort);
    serverAddr.sin_addr.s_addr = inet_addr(syslogServerIP);
    // Send the log message to the specified syslog server using sendto
    sendto(logSocket, logMessage, strlen(logMessage), 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    closelog(); // Close connection to syslog server
    close(logSocket); // Close the socket
    return 0;
}
