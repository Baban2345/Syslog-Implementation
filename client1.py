import logging

from logging.handlers import SysLogHandler
# Create a logger
logger = logging.getLogger('my_logger')
logger.setLevel(logging.INFO)
# Create a SysLogHandler and set its parameters
syslog_handler = SysLogHandler(address=('192.168.69.170', 514), facility=SysLogHandler.LOG_LOCAL3)
syslog_handler.setLevel(logging.INFO)  # Set the log level for the handler
logger.addHandler(syslog_handler)
# Create a formatter
formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
syslog_handler.setFormatter(formatter)
# Log messages

logger.warning('This is a warning message')
logger.error('An error occurred')
logger.critical('This is a critical alert')
print('sent successfully')
logger.critical('This is a critical alert By Baban')
logger.critical('This is a critical alert byhjahsgfdxfdgchjxl;')
logger.critical('This is a critical alert By manasa')
