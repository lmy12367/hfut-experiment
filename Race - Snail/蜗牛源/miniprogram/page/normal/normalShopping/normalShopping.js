// miniprogram/page/normal/normalShopping/normalShopping.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    "shoppings" : [
      {"business" : "小蜗独家装饰","shops":[{"name":"竹制框","price":10,"number":3,"checked":false},{"name":"陶瓷茶杯","price":45,"number":1,"checked":false}]},
      {"business" : "手工耿","shops":[{"name":"手工竹编自行车","price":36,"number":1,"checked":false},{"name":"竹杯子天然茶杯","price":14,"number":2,"checked":false}]}
    ],
    total : 0
  },
  checkboxChange(e) {
    // console.log(e.target.dataset.business)
    // console.log(e.detail.value)
    let business = e.target.dataset.business
    let value = e.detail.value
    let count = this.data.shoppings.length
    let that = this
    for (let i = 0; i < count; i++) {
      if (business == this.data.shoppings[i].business){
        let shops = this.data.shoppings[i].shops
        count = shops.length
        for (let j = 0; j < count; j++) {
          let str = "shoppings["+i+"].shops["+j+"].checked"
          if (value.indexOf(shops[j].name) != -1) {
            // shops[i].checked = true
            that.setData({
              [str]: true
            })
          }else{
            // shops[i].checked = false
            that.setData({
              [str]: false
            })
          }
        }
        break
      }
    }
    this.caculateTotal()
  },
  caculateTotal(){
    let count = this.data.shoppings.length
    let total = 0
    for (let i = 0; i < count; i++) {
      let temp = this.data.shoppings[i].shops
      let num = temp.length
      for (let j = 0; j < num; j++) {
        if (temp[j].checked == true) {
          total = total + temp[j].price * temp[j].number
        }
      }
    }
    
    this.setData({
     "total": total.toFixed(2)
    })
    console.log(this.data.total)
  },
  immeBuy() {
    wx.showToast({
      title: '购买成功',
      icon: 'success',
      duration: 2000
    });
    var that = this
    this.data.shoppings = null
    this.setData({
      shoppings:that.data.shoppings
    })
  },
  selectAll(e){
    let shoppings = this.data.shoppings
    let that = this
    if (e.detail.value.length == 0){
      for (let i = 0; i < shoppings.length; i++) {
        let shops = shoppings[i].shops
        for (let j = 0; j < shops.length; j++) {
          let str = "shoppings["+i+"].shops["+j+"].checked"
          that.setData({
            [str]: false
          })
        }
      }
    }else {
      for (let i = 0; i < shoppings.length; i++) {
        let shops = shoppings[i].shops
        for (let j = 0; j < shops.length; j++) {
          let str = "shoppings["+i+"].shops["+j+"].checked"
          that.setData({
            [str]: true
          })
        }
      }
    }
    that.caculateTotal()
  },
  checkOut() {
    console.log("结账！一共"+this.data.total+"元")
  },
  goBack(){
    console.log("这是回退建")
  },
  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {

  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {

  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage: function () {

  }
})