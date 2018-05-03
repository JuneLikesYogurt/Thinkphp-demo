<?php
// 本类由系统自动生成，仅供测试用途
class IndexAction extends Action {
    public function index(){
    	//$arr=array('k1'=>'Tom','k2'=>'Tom2');
    	
    	// import('ORG.My.Test');
    	// $obj=new Test;
    	// $this->assign('name',$obj);

    	// $n=$_GET['name'];
    	// $this->assign('name',$n);

    	// $this->assign('name','abc');

    	//$this->assign('sex','女');

    	//$this->assign('age','20');

        //$this->assign('number','4');

        // $arr=array('a1','b2','c3','d4','e5','f6');
        //$arr[0]=array('id'=>1,'username'=>'tom');
        //$arr[1]=array('id'=>2,'username'=>'tim');
        //$arr=array('k1'=>'v1','k2'=>'v2');
    	//$this->assign('list',$arr);

        //$user=M('User');
        //$arr=$user->select();
        $this->assign('list',$arr);
    	$this->display();
    }

    public function next(){
        $this->display();
    }
}