<?php
// 本类由系统自动生成，仅供测试用途
class IndexAction extends Action {
	public function _before_index(){
		//做判断，如果没有登陆，跳转到登录界面
		if(!isset($_SEESION['username'])||$_SEESION['username']==''){
			$this->redirect('Login/index');
		}
	}
    public function index(){
    	$city=M('City');
    	$arr=$city->select();
    	$this->assign('list',$arr);
		$this->display();
    }
    public function _after_index(){
    	echo "<script>alert('欢迎你访问本网站')</script>";
    }
}
?>