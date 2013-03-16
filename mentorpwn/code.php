<?php
include("config.php");
if(isset($_GET['id'])){
    $id = @$_GET['id'];
    $message="";
    $rm_trash = preg_replace('#\/\*.*\*\/#U','',$id); // written by genius don't try to understand
    if(!preg_match('#^[^0-9]#',$rm_trash))
    {
        // and you thought you can inject me ? haha
        if(!preg_match("#union|sub|lenght|case|convert|having|and|like|bench|sleep|mid|if|file|into|str|char|'|,#i", $rm_trash)){
        $req = mysql_query("SELECT * FROM users WHERE id=$rm_trash");
        if(@mysql_num_rows($req)!=0)
            $message = "Sure, we have it in database";
        else
            $message="Houston, we have a problem!";
        }
        else
            $message="Houston, we have a filter!";
    }
}
?>