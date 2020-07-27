# service vsftpd restart
echo "pasv_address=$ip"
echo "pasv_address=$ip" >> /etc/vsftpd/vsftpd.conf
vsftpd /etc/vsftpd/vsftpd.conf