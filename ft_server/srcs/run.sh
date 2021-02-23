#!/bin/bash
service mysql start

echo "CREATE DATABASE IF NOT EXISTS wordpress;" | mysql -u root --skip-password
echo "CREATE USER 'wonjlee'@'localhost' IDENTIFIED BY '0403';" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'wonjlee'@'localhost' WITH GRANT OPTION;" | mysql -u root --skip-password

service nginx start
service php7.3-fpm start

bash
