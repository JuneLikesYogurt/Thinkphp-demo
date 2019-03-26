<?php
// 本类由系统自动生成，仅供测试用途
class IndexAction extends CommonAction {
    public function index(){
		// //判断用户是否登录过，通过session
		// if(isset($_SESSION['username']) && $_SESSION['username']!=''){
		// 	$this->display();
		// }else{
		// 	$this->redirect('Login/login');
		// }
        $this->display();
    }
    public function top(){
        //$this->assign('name',$_SESSION['username']);
    	$this->display();
    }
    public function left(){
    	$this->display();
    }
    public function right(){
    	$this->display();
    }
}