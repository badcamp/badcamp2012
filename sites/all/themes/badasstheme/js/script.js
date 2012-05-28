$(document).ready(function() {
  if ($("#block-badcamp-blimp").length > 0) {
    $("#block-badcamp-blimp").click(function() {
      return false;
    })
    moveAround();
  }
});

function moveAround() {
  var $left = 0;
  var $top = 0;
  var $distance = 40;

  var $p = $("#block-badcamp-blimp").position();

  var $l_distance = $left + Math.floor(Math.random()*$distance);
  var $t_distance = $top + Math.floor(Math.random()*$distance);

  var $l_difference = $p.left - $l_distance;
  var $t_difference = $p.top - $t_distance;

  var $m = Math.sqrt(Math.pow($l_difference, 2) + Math.pow($t_difference, 2));

  var $time = $m/4;

  $("#block-badcamp-blimp").animate({
    left: $l_distance,
    top: $t_distance
  },
  $time*1500,
  "easeInOutSine",
  function(){
    setTimeout("moveAround()", 2000);
  })
}

function pirateArg() {
  $("#logo").addClass("pirate-arg");
  setTimeout("pirateQuiet()", 2000);
}

function pirateQuiet(){
  $("#logo").removeClass("pirate-arg");
};

// An excerpt from http://gsgd.co.uk/sandbox/jquery/easing/jquery.easing.1.3.js
jQuery.extend(jQuery.easing, {
  easeInOutSine: function (x, t, b, c, d) {
    return -c/2 * (Math.cos(Math.PI*t/d) - 1) + b;
  }
});
