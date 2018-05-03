<?php
	class LoginAction extends Action{
		public function index(){
			$this->display();
		}
		public function do_login(){
			$username=$_POST['username'];
			$password=$_POST['password'];
			$user=M('User');
			$where['username']=$username;
			$where['password']=$password;
			$c=$user->where($where)->count();
			if($c>0){
				$_SESSION['username']=$username;
				$this->redirect('Index/index');
			}else{
				$this->error('用户不能登录');
			}
		}
	}
?>