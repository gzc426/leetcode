String.prototype.reverse = function() {
    return this.split('').reverse().join('');
}

var reverseWords = function(s) {
    return s.split(' ').map(str => str.reverse()).join(' ');
};
