jQuery.fn.insertComment=function(E,J,I,D){var K=this.id||"threadShow";var F=E||"95%";var B=J||10;var G=I||"nCmts";var C=D||"icomments";var A=[];var H=0;jQuery.noConflict();jQuery(document).ready(function(M){var a=[];var Q=0;var c=0;var R='<img id="imgPlHdr" src="//www.ibm.com/developerworks/i/spaces/onex/animateloader_onex.gif" />';var X=function(){A=M.makeArray(M("div.metavalue"));var f={};M.each(A,function(){var g=jQuery(this).text().split("=");f[g[0]]=encodeURIComponent(g[1])});A=f};var b=function(f){a=[];
H=M("totalCount",f).text();if(!H){H=0}M("comment",f).each(function(h){var g=T(this);a.push(g)})};var P=function(h,f){var g=(typeof f!="undefined"&&f=="true")?H:Q+B;g=(H!=0&&g>H)?H:g;Q+=B;Q=(H!=0&&Q>H)?H:Q;L(0,g,function(){M("#numCmts").html(""+H);if(H==0){M("#"+G).html(H+'&nbsp;(<a href="#icomments">Add comments</a>)');(c)?M("div#cmtSect").html(O()):M("div#cmtSect").html(U())}else{M("#"+G).html(H+'&nbsp;(<a href="#icomments">View or add comments</a>)')}M("#imgPlHdr").remove();h()})};var S=function(){return'<div id="paging"><p><a id="lastCmts" class="dw-icomment-link">Show '+B+' most recent comments</a><span id="cmtDivider"> <span class="dw-bar">|</span> </span><a id="nextCmts" class="dw-icomment-link">Show next '+B+' comments</a><span id="cmtDivider2"> <span class="dw-bar">|</span> </span><a id="viewAllCmts" class="dw-icomment-link">Show all comments</a></p></div>'
};var e=function(f){if(d()){M.ajax({type:"POST",url:"/developerworks/niagara/commentjsp/WSComment.jsp",data:"action=pc&url="+A.ArticleID+"&cn=test"+((f!=undefined&&f!=null&&typeof (f)=="boolean")?"&an="+f:"")+"&cb="+encodeURIComponent(M("#newCmt").attr("value"))+"&rn="+Math.random(),dataType:"xml",beforeSend:function(){M("#infoCmt").html('<p><span class="ibm-error">Posting comment...</span></p>');M(":button#clearCmt,:button#postCmt,:button#postAnonCmt,:button#cancelCmt").attr("disabled",true)},complete:function(){M("#newCmt,:button#clearCmt,:button#postCmt,:button#postAnonCmt,:button#cancelCmt").removeAttr("disabled");
M("#infoCmt").text("")},success:function(g){if(M("response",g).text()=="ok"){M("#newCmt").attr("value","");M("#commentForm").hide();M("div#cmtSect").html("");M("#lastCmts").click();M("#addCmtLk,#addCmtLk2").show()}else{alert(M("error",g).text())}},error:function(){alert("Your comment cannot be posted at this time.  Please try again later.")}})}};var d=function(){var f=false;M("#newCmt").attr("disabled",true);M("#newCmt").attr("value",M.trim(M("#newCmt").attr("value")));if(M("#newCmt").attr("value")==undefined){M("#infoCmt").html('<p><span class="ibm-error">Please enter a comment.</span></p>');
M("#newCmt").attr("disabled",false)}else{f=true}return f};var L=function(h,f,g){M.ajax({type:"GET",url:"/developerworks/niagara/commentjsp/WSComment.jsp",data:"action=gc&url="+A.ArticleID+"&start="+h+"&range="+f+"&rn="+Math.random(),dataType:"xml",success:function(i){b(i);M("div#cmtSect").html(a.join(""))},error:function(i){c=1;M("div#cmtSect").html(O())},complete:function(){g()},async:true})};var Z=function(){var f=false;M.ajax({type:"GET",async:false,url:"/developerworks/niagara/commentjsp/WSComment.jsp",data:"action=login&rn="+Math.random(),dataType:"xml",success:function(g){f=M.trim(M("status",g).text()).toLowerCase()
},error:function(g){alert("Your login status cannot be verified at this point. Please try again later.")}});return f};var V=function(){return'<p><span id="numCmts"></span>&nbsp;comments <span class="dw-bar">|</span> <a class="loginLk">Sign in</a><a id="addCmtLk" class="dw-icomment-link">Add comment</a><a class="dw-icomment-report" href="http://www-128.ibm.com/developerworks/forums/forum.jspa?forumID=1317">Report inappropriate content</a></p><div class="ibm-alternate-rule"><hr /></div>'};var N=function(){return((H>0)?'<div class="ibm-alternate-rule"><hr /></div>':"")+'<p><a class="loginLk">Sign in</a><a id="addCmtLk2" href="#'+C+'">Add comment</a></p><div class="ibm-alternate-rule"><hr /></div><div class="ibm-alternate-rule"><hr /></div>'
};var T=function(f){var g="";if(M("profileurl",f).text().length>0){g='<a href="'+M("profileurl",f).text()+'">'+M("author",f).text()+"</a>"}else{g=M("author",f).text()}return'<div class="comment"><div class="dw-icomment-container"><table class="dw-icomment-body" cellpadding="0" cellspacing="0" width="100%"><tr><td><p>'+M("body",f).text()+'</p></td></tr><tr><td><p class="ibm-item-note-alternate">Posted by <b>'+g+"</b> on "+M("time",f).text()+"</p></td></tr></table></div></div>"};var U=function(){return'<div class="comment"><div class="dw-icomment-container"><table class="dw-icomment-body" cellpadding="0" cellspacing="0" width="100%"><tr><td><p>No comments posted for this article</p></td></tr></table></div></div>'
};var O=function(){return'<div class="comment"><div class="dw-icomment-container"><table class="dw-icomment-body" cellpadding="0" cellspacing="0" width="100%"><tr><td><p>There is a problem in retrieving the comments.  Please refresh the page later.</p></td></tr></table></div></div>'};var Y=function(){return'<div id="commentForm"><div class="ibm-container"><h2>Add a comment</h2><div class="ibm-container-body"><p>The field indicated with an asterisk (<span class="ibm-required">*</span>) is required to complete this transaction.</p><span id="infoCmt" /><div class="ibm-rule"><hr /></div><form method="post" action="" class="ibm-column-form" enctype="multipart/form-data" focus="name" name="form"><p><label for="newCmt">Comment:<span class="ibm-required">*</span></label><br /><textarea name="newCmt" id="newCmt" cols="120" rows="4"></textarea></p><div class="ibm-alternate-rule"><hr /></div><p class="ibm-buttons-row"><input value="Post" type="button" name="postCmt" class="ibm-btn-arrow-sec" id="postCmt" /><span class="ibm-sep">&nbsp;</span><input value="Post anonymously" type="button" name="postAnonCmt" class="ibm-btn-arrow-sec" id="postAnonCmt" /><span class="ibm-sep">&nbsp;</span><input value="Clear comment" type="button" name="clearCmt" class="ibm-btn-cancel-sec" id="clearCmt" /><span class="ibm-sep">&nbsp;</span><input value="Cancel" type="button" name="cancelCmt" class="ibm-btn-cancel-sec" id="cancelCmt" /></p></form></div></div></div>'
};X();var W="";W+=V();W+=Y();W+='<div id="cmtSect"></div>';W+=S();W+=N();W=R+'<div id="cmtTog" style="display:none">'+W+"</div>";M("div#"+K).html(W);M("#lastCmts").click(function(){Q=0;H=0;M("div#cmtSect").append(R);P(function(){M("#lastCmts,#cmtDivider,#nextCmts,#cmtDivider2,#viewAllCmts").hide();M("#cmtTog").show();if(Q<H){M("#nextCmts,#cmtDivider2,#viewAllCmts").show()}});return false}).click();M("#nextCmts").click(function(){if(Q<H){M("div#cmtSect").append(R);P(function(){if(Q>B){M("#lastCmts,#cmtDivider").show()
}if((H-Q)<=B){M("#nextCmts,#cmtDivider2").hide()}if(Q>=H){M("#cmtDivider,#nextCmts,#cmtDivider2,#viewAllCmts").hide()}})}return false});M("#viewAllCmts").click(function(){M("div#cmtSect").append(R);P(function(){if(Q>B){M("#lastCmts,#cmtDivider").show()}M("#nextCmts,#cmtDivider").hide();M("#viewAllCmts,#cmtDivider2").hide()},"true")});M("#addCmtLk").click(function(){(Z()=="true")?M("#commentForm").show():M(".loginLk").show();M("#addCmtLk,#addCmtLk2").hide();return false});M(".loginLk").hide();M(".loginLk").attr("href","https://www.ibm.com/developerworks/dwwi/DWAuthRouter?m=loginpage&d="+encodeURIComponent(window.location+"#"+C));
M("#addCmtLk2").click(function(){M("#addCmtLk").click();return(Z()=="true")?true:false});M("#commentForm").hide();M(":button#clearCmt").click(function(){M("#newCmt").attr("value","");return false});M(":button#postCmt").click(function(){e();return false});M(":button#postAnonCmt").click(function(){e(true);return false});M(":button#cancelCmt").click(function(){M("#commentForm").hide();M("#addCmtLk,#addCmtLk2").show();return false})});return jQuery};