<?php
	class MessageModel extends Model{
		protected $_auto=array(
			array('time','time',1,'function'),
			array('uid','getId',1,'callback')
		);
		protected function getId(){
			return $_SESSION['id'];
		}
	}
?>