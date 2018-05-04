from PIL import Image
import sys
def resize(img_name):
    img = Image.open(img_name)
    width, height = img.size
    if width > height:
        rate = width / height
    else:
        rate = height / width
    img = img.resize((150 * int(rate), 150), Image.ANTIALIAS)
    img.save(img_name)
resize(sys.argv[1])
