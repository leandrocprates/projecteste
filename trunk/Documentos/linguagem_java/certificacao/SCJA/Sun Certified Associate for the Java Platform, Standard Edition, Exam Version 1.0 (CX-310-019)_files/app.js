document.observe('dom:loaded', function(){
    new OCOM.DropDown({element: $('navigation'), vertical_adjustment: -2});
});