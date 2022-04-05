// miniprogram/page/disable/disableRelease/disableRelease.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    works:[]
  },
  learnMore(){
    wx.navigateTo({
      url: '../../normal/normalAcitivtyDetails/normalActivityDetails',
    })
  },
  goChange(e){
    wx.navigateTo({
      url:'../disableReleaseGoods/disableReleaseGoods'
    })
  },
  doAppointment(){
    wx.showToast({
      title: '正在预约',
      icon: 'loading',
      duration: 500
    })
    setTimeout(() => {
      wx.showToast({
        title: '预约成功',
        icon: 'success',
        duration: 500
      })
    }, 500);
  },
  appointmentIsin(){
    wx.showToast({
      title: '已经预约啦！',
      icon: 'none',
      duration: 500
    })
  },
  appointmentFull(){
    wx.showToast({
      title: '已经约满啦！',
      icon: 'none',
      duration: 500
    })
  },
  goHome(){
    wx.redirectTo({
      url: '../disableHome/disableHome',
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
  goMyInfo(){
    wx.redirectTo({
      url: '../disableMyInfo/disableMyInfo',
    })
  },
  goRelease(){
    wx.navigateTo({
      url: '../disableReleaseGoods/disableReleaseGoods',
    })
  },
  getByPhone(){
    var that = this
    wx.request({
      url: 'https://liangye-xo.xyz:10086/artistWork/phone/13202561234',
      method:'GET',
      success:function(res){
        that.setData({
          works: res.data.data
        })
        console.log(res.data.data)
        console.log(that.data.works)
      }
    })
  },
  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    this.getByPhone()
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