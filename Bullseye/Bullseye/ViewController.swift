//
//  ViewController.swift
//  Bullseye
//
//  Created by Imran S on 2/10/20.
//  Copyright © 2020 Imran. All rights reserved.
//

import UIKit


class ViewController: UIViewController {

var targetValue = 0
var currentValue: Int = 0
var score = 0
var round: Int = 0

@IBOutlet weak var roundLabel: UILabel!
@IBOutlet weak var scoreLabel: UILabel!
@IBOutlet weak var slider: UISlider!
@IBOutlet weak var targetLabel: UILabel!

    override func viewDidLoad() {
        super.viewDidLoad()
        currentValue = lroundf(slider.value)
        targetValue = Int.random(in: 1...100)
        startNewRound()
        
        let thumbImageNormal = UIImage(named: "SliderThumb-Normal")!
        slider.setThumbImage(thumbImageNormal, for: .normal)
        
        let thumbImageHighlighted = UIImage(named: "SliderThumb-Highlighted")!
        slider.setThumbImage(thumbImageHighlighted, for: .highlighted)
        let insets = UIEdgeInsets(top: 0, left: 14, bottom: 0, right:
        14)
       
        let trackLeftImage = UIImage(named: "SliderTrackLeft")!
        
        let trackLeftResizable = trackLeftImage.resizableImage(withCapInsets: insets)
        slider.setMinimumTrackImage(trackLeftResizable, for: .normal)
        
        let trackRightImage = UIImage(named: "SliderTrackRight")!
        
        let trackRightResizable = trackRightImage.resizableImage(withCapInsets: insets)
        
        slider.setMaximumTrackImage(trackRightResizable, for: .normal)
    }
    
    override func viewWillAppear(_ animated: Bool){
        super.viewWillAppear(animated);
        self.navigationController?.navigationBar.isHidden = true; 
    }

    @IBAction func showAlert(){
    let difference = abs(targetValue - currentValue)
    var points = 100 - difference
        
        let title: String
          if difference == 0 {
            title = "Perfect!"
            points += 50
          } else if difference < 5 {
            title = "You almost had it!"
            if difference == 1{
                points += 50
            }
          } else if difference < 10 {
            title = "Pretty good!"
        } else {
        title = "Not even close..." }
        score += points
        
        
        
    let message = "You scored \(points) points"
    
    
    let alert = UIAlertController(title: title,message: message,preferredStyle: .alert)
        
        let action = UIAlertAction(title: "OK", style: .default, handler: { _ in
        self.startNewRound() })

        
        alert.addAction(action)
        present(alert, animated: true, completion: nil)
        
        
    }
    
     @IBAction func sliderMoved(_ slider: UISlider) {
        currentValue = lroundf(slider.value)
        
    }
    
    @IBAction func startNewGame() {
      score = 0
      round = 0
      startNewRound()
    }
    
    func startNewRound() {
    round += 1
    targetValue = Int.random(in: 1...100)
    currentValue = 50
    slider.value = Float(currentValue)
    updateLabels()
    //round += 1
    }
    
     func updateLabels() {
    targetLabel.text = String(targetValue)
        scoreLabel.text = String(score)
        roundLabel.text = String(round)
    }
    
    
}
