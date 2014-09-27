var mpgjs = require('../index'),
    assert = require('assert'),
    path = require('path');

describe('isValid mpgjs tests', function() {

  it('should return false when file is not a valid mp3 file', function() {
    var str = mpgjs.isValid("not-valid-file");
    assert.equal(str, false);
  });

  it('should return true when the file IS a valid mp3 file', function() {
    var file_path = path.join(__dirname, 'data', 'test.mp3'),
        str = mpgjs.isValid(file_path);
        
    assert.equal(str, true);
  });

});
