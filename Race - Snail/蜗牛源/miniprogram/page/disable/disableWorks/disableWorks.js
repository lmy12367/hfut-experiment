// miniprogram/page/disable/disableWorks/disableWorks.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    index:1,
    workdetails:[],
    cateItems: [
      {
        cate_id: 1,
        cate_name: 'Go后端工程',
      },
      {
        cate_id: 2,
        cate_name: 'Java后端工程',
      },
      {
        cate_id: 3,
        cate_name: '手工制作'
      },
      {
        cate_id: 4,
        cate_name: '收银员'
      },
      {
        cate_id: 5,
        cate_name: '算法工程师'
      },
      {
        cate_id: 6,
        cate_name: '会计'
      },
    ],
    curNav: 1,
    curIndex: 0,
    curName:"Go后端工程",
    all_works:[
      
    ]
  },
  switchRightTab: function (e) {
    let id = e.target.dataset.id, index = e.target.dataset.index;
    let name = e.target.dataset.name
    this.setData({
      curNav: id,
      curIndex: index,
      curName: name
    })
    this.getByName(this.data.curName)
  },
  switchBar(e) {
    var that = this
    var i = e.currentTarget.dataset.index
    if (i != that.data.index) {
      var str1 = "all_works["+i+"].state"
      var str2 = "all_works["+that.data.index+"].state"
      console.log(that.data.index)
      that.setData({
        [str1] : 'selected',
        [str2] : 'noselected',
        index : i
      })
    }
  },
  toHome(){
    wx.redirectTo({
      url: '../disableHome/disableHome',
    })
  },
  toRelease(){
    wx.redirectTo({
      url: '../disableRelease/disableRelease',
    })
  },
  toStudy(){
    wx.redirectTo({
      url: '../disableStudyVedio/disableStudyVedio',
    })
  },
  toMyInfo(){
    wx.redirectTo({
      url: '../disableMyInfo/disableMyInfo',
    })
  },
  getByName(name){
    var that = this
    wx.request({
      url: 'http://localhost:8080/hirement/getByName',
      data:{
        name:name
      },
      method:'GET',
      success:function(res){
        that.setData({
          workdetails: res.data.data
        })
        console.log(res.data.data)
        console.log(that.data.workdetails)
      }
    })
  },
  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    var that = this
    this.getByName(that.data.curName)
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