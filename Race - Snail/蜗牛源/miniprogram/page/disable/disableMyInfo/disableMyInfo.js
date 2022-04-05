// miniprogram/page/disable/disableMyInfo/disableMyInfo.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    "user": {
      "name" : "名媛",
      "phone" : "13012345678",
      "power" : 3500,
      "vip" : "V3"
    }
  },
  goMyAdress(){
    wx.navigateTo({
      url: '../disableMyAdress/disableMyAdress',
    })
  },
  goHome(){
    wx.redirectTo({
      url: '../disableHome/disableHome',
    })
  },
  goRelease(){
    wx.redirectTo({
      url: '../disableRelease/disableRelease',
    })
  },
  goStudy(){
    wx.redirectTo({
      url: '../disableStudyVedio/disableStudyVedio',
    })
  },
  goWork(){
    wx.redirectTo({
      url: '../disableWorks/disableWorks',
    })
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